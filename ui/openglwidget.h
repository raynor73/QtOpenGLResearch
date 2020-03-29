#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QObject>
#include <QElapsedTimer>
#include <QOpenGLWidget>
#include "glm/glm.hpp"
#include "domain/mesh.h"
#include "data/openglgeometryrepository.h"
#include "data/openglshadersrepository.h"
#include "data/assets/opengltexturesrepository.h"
#include "data/openglerrordetector.h"
#include "data/qtuserinputmeshcontroller.h"
#include "data/qtdisplaymetricsrepository.h"

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
    QElapsedTimer m_dtTimer;

    Mesh m_mesh;
    glm::vec3 m_meshEulerAngles;
    glm::vec3 m_meshPosition;
    float m_meshRotationSpeed = 1; // rad per second
    float m_meshMovementSpeed = 1;

    OpenGLErrorDetector m_openGLErrorDetector;
    UserInput m_userInput;
    OpenGLGeometryRepository m_openGLGeometryRepository;
    OpenGLShadersRepository m_openGLShadersRepository;
    OpenGLTexturesRepository m_openGLTexturesRepository;
    QtUserInputMeshController m_meshController;
    QtDisplayMetricsRepository m_displayMetrixRepository;

    void initScene();
    void render();
    void dispatchInput(float dt);
};

#endif // OPENGLWIDGET_H
