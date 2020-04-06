#ifndef OPENGLWIDGET2_H
#define OPENGLWIDGET2_H

#include <QObject>
#include <QOpenGLWidget>
#include <QElapsedTimer>
#include <memory>
#include "data/openglerrordetector.h"
#include "data/userinput.h"
#include "data/qtdisplaymetricsrepository.h"
#include "data/researchrenderingengine.h"
#include "domain/scenes/researchscene.h"

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
    QtDisplayMetricsRepository m_displayMetrixRepository;
    GameObjectsHierarchyContainer m_gameObjectsHierarchyContainer;
    ResearchRenderingEngine m_renderingEngine;

    std::shared_ptr<ResearchScene> m_scene;
};

#endif // OPENGLWIDGET2_H
