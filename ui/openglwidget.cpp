#include <QTimer>
#include <QDebug>
#include <QOpenGLFunctions_4_5_Core>
#include "openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent, float fpsLimit) :
    QOpenGLWidget(parent),
    m_fpsPeriod(1000 / fpsLimit)
{}

void OpenGLWidget::initializeGL()
{
    glClearColor(0, .5, 0, 1);
}

void OpenGLWidget::paintGL()
{
    render();

    m_renderTimer.start();

    int delay = m_fpsPeriod - m_renderTimer.elapsed();
    QTimer::singleShot(delay > 0 ? delay : 1, this, SLOT(update()));
}

void OpenGLWidget::resizeGL(int, int) {}

void OpenGLWidget::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
