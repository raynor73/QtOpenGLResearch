#include <QDebug>
#include <assimp/cimport.h>
#include "openglwidget2.h"

OpenGLWidget2::OpenGLWidget2(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit),
    m_openGLGeometryRepository(OpenGLGeometryRepository(m_openGLErrorDetector)),
    m_openGLShadersRepository(OpenGLShadersRepository(m_openGLErrorDetector)),
    m_openGLTexturesRepository(OpenGLTexturesRepository(m_openGLErrorDetector))
{}

void OpenGLWidget2::initializeGL()
{
    m_openGLShadersRepository.removeAllShadersAndPrograms();
    m_openGLGeometryRepository.removeAllBuffers();
    m_openGLTexturesRepository.removeAllTextures();

    C_STRUCT aiLogStream stream = aiGetPredefinedLogStream(aiDefaultLogStream_STDOUT, NULL);
    aiAttachLogStream(&stream);

    qDebug() << QString::fromLatin1(reinterpret_cast<const char *>(glGetString(GL_VERSION))) << "\n";
}

void OpenGLWidget2::paintGL()
{

}

void OpenGLWidget2::resizeGL(int, int) {}
