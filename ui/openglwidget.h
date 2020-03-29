#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QObject>
#include <QElapsedTimer>
#include <QOpenGLWidget>
#include "domain/mesh.h"
#include "data/openglgeometryrepository.h"
#include "data/openglshadersrepository.h"
#include "data/openglerrordetector.h"

class OpenGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget* parent, float fpsLimit);

protected:
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int w, int h) override;

private:
    int m_fpsPeriod;
    QElapsedTimer m_renderTimer;

    Mesh m_mesh;

    OpenGLErrorDetector m_openGLErrorDetector;
    OpenGLGeometryRepository m_openGLGeometryRepository;
    OpenGLShadersRepository m_openGLShadersRepository;

    void initScene();
    void render();
};

#endif // OPENGLWIDGET_H
