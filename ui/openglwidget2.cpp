#include <QDebug>
#include <assimp/cimport.h>
#include "openglwidget2.h"

OpenGLWidget2::OpenGLWidget2(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit),
    m_renderingEngine(m_gameObjectsHierarchyContainer, m_displayMetrixRepository, m_openGLErrorDetector)
{}

void OpenGLWidget2::initializeGL()
{
    qDebug() << QString::fromLatin1(reinterpret_cast<const char *>(glGetString(GL_VERSION))) << "\n";

    m_scene = std::make_shared<ResearchScene>(m_gameObjectsHierarchyContainer);
    m_scene->onStart();
}

void OpenGLWidget2::paintGL()
{
    if (m_openGLErrorDetector.isOpenGLErrorDetected()) {
        return;
    }

    m_scene->onUpdate();
    m_gameObjectsHierarchyContainer.onUpdate();
    m_renderingEngine.render();
}

void OpenGLWidget2::resizeGL(int, int) {}
