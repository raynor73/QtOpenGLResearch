#ifndef OPENGLWIDGET2_H
#define OPENGLWIDGET2_H

#include <QObject>
#include <QOpenGLWidget>
#include <QElapsedTimer>
#include "data/openglerrordetector.h"
#include "data/userinput.h"
#include "data/openglgeometryrepository.h"
#include "data/openglshadersrepository.h"
#include "data/assets/opengltexturesrepository.h"
#include "data/qtdisplaymetricsrepository.h"

class OpenGLWidget2 : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget2(QWidget* parent, float fpsLimit);

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

private:
    int m_fpsPeriod;
    QElapsedTimer m_renderTimer;

    OpenGLErrorDetector m_openGLErrorDetector;
    UserInput m_userInput;
    OpenGLGeometryRepository m_openGLGeometryRepository;
    OpenGLShadersRepository m_openGLShadersRepository;
    OpenGLTexturesRepository m_openGLTexturesRepository;
    QtDisplayMetricsRepository m_displayMetrixRepository;

};

#endif // OPENGLWIDGET2_H
