#ifndef QTUSERINPUTMESHCONTROLLER_H
#define QTUSERINPUTMESHCONTROLLER_H

#include <QObject>
#include "userinput.h"
#include "domain/meshcontroller.h"

class QtUserInputMeshController : public QObject, public MeshController
{
    Q_OBJECT

public:
    QtUserInputMeshController(UserInput& userInput);
    QtUserInputMeshController(const QtUserInputMeshController& other);
    virtual ~QtUserInputMeshController() override;

    virtual float xRotationFactor() const override { return m_xRotationFactor; };
    virtual float yRotationFactor() const override { return m_yRotationFactor; };
    virtual float zRotationFactor() const override { return m_zRotationFactor; };

public slots:
    void onKeyEvent(QKeyEvent);
    void onMouseEvent(QMouseEvent);

private:
    UserInput& m_userInput;

    float m_xRotationFactor = 0;
    float m_yRotationFactor = 0;
    float m_zRotationFactor = 0;
};

#endif // QTUSERINPUTMESHCONTROLLER_H
