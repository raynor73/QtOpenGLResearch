#include <QTimer>
#include <QDebug>
#include <QOpenGLFunctions_4_5_Core>
#include <map>
#include <string>
#include <iostream>
#include "openglwidget.h"
#include "utils.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit),
    m_openGLGeometryRepository(OpenGLGeometryRepository(m_openGLErrorDetector)),
    m_openGLShadersRepository(OpenGLShadersRepository(m_openGLErrorDetector)),
    m_openGLTexturesRepository(OpenGLTexturesRepository(m_openGLErrorDetector))
{}

void OpenGLWidget::initializeGL()
{
    initScene();
}

void OpenGLWidget::paintGL()
{
    render();

    m_renderTimer.start();

    int delay = m_fpsPeriod - m_renderTimer.elapsed();
    QTimer::singleShot(delay > 0 ? delay : 1, this, SLOT(update()));
}

void OpenGLWidget::resizeGL(int, int) {}

void OpenGLWidget::initScene()
{
    glClearColor(0, .5, 0, 1);

    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(Vector3f(-0.5, -0.5, 0.0), Vector2f(0, 0)));
    vertices.push_back(Vertex(Vector3f( 0.5, -0.5, 0.0), Vector2f(1, 0)));
    vertices.push_back(Vertex(Vector3f( 0.5,  0.5, 0.0), Vector2f(1, 1)));
    vertices.push_back(Vertex(Vector3f(-0.5,  0.5, 0.0), Vector2f(0, 1)));

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

    auto textureInfo = m_openGLTexturesRepository.findTexture("bricks");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureInfo.texture());
    glUniform1i(shaderProgramInfo.textureUniform(), 0);

    glDrawElements(
        GL_POLYGON,
        iboInfo.numberOfIndices(),
        GL_UNSIGNED_SHORT,
        0
    );

    glDisableVertexAttribArray(shaderProgramInfo.positionAttribute());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLWidget::render");
}
