#include <QDebug>
#include <assimp/cimport.h>
#include "openglwidget2.h"

OpenGLWidget2::OpenGLWidget2(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit),
    m_renderingEngine(m_displayMetrixRepository, m_openGLErrorDetector, m_gameObjectsHierarchyContainer)
{}

void OpenGLWidget2::initializeGL()
{
    qDebug() << QString::fromLatin1(reinterpret_cast<const char *>(glGetString(GL_VERSION))) << "\n";
}

void OpenGLWidget2::paintGL()
{
    if (m_openGLErrorDetector.isOpenGLErrorDetected()) {
        return;
    }

    m_gameObjectsHierarchyContainer.onUpdate();
    m_renderingEngine.render();
}

void OpenGLWidget2::resizeGL(int, int) {}
