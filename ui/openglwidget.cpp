#include <QTimer>
#include <QDebug>
#include <QOpenGLFunctions_4_5_Core>
#include <map>
#include <string>
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "openglwidget.h"
#include "utils.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit),
    m_openGLGeometryRepository(OpenGLGeometryRepository(m_openGLErrorDetector)),
    m_openGLShadersRepository(OpenGLShadersRepository(m_openGLErrorDetector)),
    m_openGLTexturesRepository(OpenGLTexturesRepository(m_openGLErrorDetector)),
    m_meshController(QtUserInputMeshController(m_userInput))
{}

void OpenGLWidget::initializeGL()
{
    initScene();
}

void OpenGLWidget::paintGL()
{
    m_renderTimer.start();

    dispatchInput(m_dtTimer.nsecsElapsed() / 1e9);
    render();

    int delay = m_fpsPeriod - m_renderTimer.elapsed();
    QTimer::singleShot(delay > 0 ? delay : 1, this, SLOT(update()));

    m_dtTimer.start();
}

void OpenGLWidget::resizeGL(int, int) {}

void OpenGLWidget::initScene()
{
    glClearColor(0, .5, 0, 1);

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0, 0)));
    vertices.push_back(Vertex(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1, 0)));
    vertices.push_back(Vertex(glm::vec3( 0.5,  0.5, 0.0), glm::vec2(1, 1)));
    vertices.push_back(Vertex(glm::vec3(-0.5,  0.5, 0.0), glm::vec2(0, 1)));

    std::vector<uint16_t> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(3);

    Mesh mesh(vertices, indices);

    m_mesh = mesh;

    m_openGLGeometryRepository.createStaticVertexBuffer("plane", extractVerticesData(mesh));
    m_openGLGeometryRepository.createStaticIndexBuffer("plane", mesh.indices());

    m_openGLShadersRepository.createVertexShader(
                "vertex_shader",
                loadTextFromResources("://resources/shaders/vertexShader.glsl")
    );
    m_openGLShadersRepository.createFragmentShader(
                "fragment_shader",
                loadTextFromResources("://resources/shaders/fragmentShader.glsl")
    );
    m_openGLShadersRepository.createShaderProgram(
                "shader",
                m_openGLShadersRepository.findVertexShader("vertex_shader"),
                m_openGLShadersRepository.findFragmentShader("fragment_shader")
    );

    m_openGLTexturesRepository.createTexture("bricks", "://resources/textures/bricks.jpg");

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLWidget::initScene");
}

void OpenGLWidget::render()
{
    if (m_openGLErrorDetector.isOpenGLErrorDetected()) {
        return;
    }

    glClear(GL_COLOR_BUFFER_BIT);

    auto vbo = m_openGLGeometryRepository.findVbo("plane");
    auto iboInfo = m_openGLGeometryRepository.findIbo("plane");

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboInfo.ibo());

    auto shaderProgramInfo = m_openGLShadersRepository.findShaderProgram("shader");
    glUseProgram(shaderProgramInfo.shaderProgram());

    glVertexAttribPointer(
            shaderProgramInfo.positionAttribute(),
            Vertex::VERTEX_COORDINATE_COMPONENTS,
            GL_FLOAT,
            false,
            Vertex::VERTEX_COMPONENTS * sizeof (float),
            0
    );
    glEnableVertexAttribArray(shaderProgramInfo.positionAttribute());

    glVertexAttribPointer(
            shaderProgramInfo.uvAttribute(),
            Vertex::VERTEX_UV_COMPONENTS,
            GL_FLOAT,
            false,
            Vertex::VERTEX_COMPONENTS * sizeof (float),
            reinterpret_cast <void *>(Vertex::VERTEX_COORDINATE_COMPONENTS * sizeof (float))
    );
    glEnableVertexAttribArray(shaderProgramInfo.uvAttribute());

    auto textureInfo = m_openGLTexturesRepository.findTexture("bricks");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureInfo.texture());
    glUniform1i(shaderProgramInfo.textureUniform(), 0);

    auto projectionMatrix = glm::perspective(
                45.0f,
                float(m_displayMetrixRepository.width()) / m_displayMetrixRepository.height(),
                0.1f, 1000.f
    );

    auto viewMatrix = glm::lookAt(glm::vec3(0, 0, 1), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    auto modelMatrix = glm::rotate(glm::mat4(1), m_meshEulerAngles.x, glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, m_meshEulerAngles.y, glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, m_meshEulerAngles.z, glm::vec3(0, 0, 1));

    auto mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
    glUniformMatrix4fv(shaderProgramInfo.mvpMatrixUniform(), 1, false, glm::value_ptr(mvpMatrix));

    glDrawElements(
        GL_POLYGON,
        iboInfo.numberOfIndices(),
        GL_UNSIGNED_SHORT,
        0
    );

    glDisableVertexAttribArray(shaderProgramInfo.positionAttribute());
    glDisableVertexAttribArray(shaderProgramInfo.uvAttribute());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLWidget::render");
}

void OpenGLWidget::dispatchInput(float dt)
{
    m_meshEulerAngles.x += m_meshController.xRotationFactor() * m_meshRotationSpeed * dt;
    m_meshEulerAngles.y += m_meshController.yRotationFactor() * m_meshRotationSpeed * dt;
    m_meshEulerAngles.z += m_meshController.zRotationFactor() * m_meshRotationSpeed * dt;
}
