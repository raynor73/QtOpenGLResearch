#include <QDebug>
#include "qtuserinputmeshcontroller.h"

QtUserInputMeshController::QtUserInputMeshController(UserInput& userInput) :
    m_userInput(userInput)
{
    connect(&m_userInput, &UserInput::onKeyEvent, this, &QtUserInputMeshController::onKeyEvent);
    connect(&m_userInput, &UserInput::onMouseEvent, this, &QtUserInputMeshController::onMouseEvent);
}

QtUserInputMeshController::QtUserInputMeshController(const QtUserInputMeshController& other) :
    m_userInput(other.m_userInput)
{}

QtUserInputMeshController::~QtUserInputMeshController()
{
    disconnect(&m_userInput, &UserInput::onKeyEvent, this, &QtUserInputMeshController::onKeyEvent);
    disconnect(&m_userInput, &UserInput::onMouseEvent, this, &QtUserInputMeshController::onMouseEvent);
}

void QtUserInputMeshController::onKeyEvent(QKeyEvent event)
{
    switch (event.key()) {
    case Qt::Key_Q:
        if (event.type() == QEvent::KeyPress)
            m_zRotationFactor += 1;
        else
            m_zRotationFactor -= 1;
        break;

    case Qt::Key_E:
        if (event.type() == QEvent::KeyPress)
            m_zRotationFactor -= 1;
        else
            m_zRotationFactor += 1;
        break;

    case Qt::Key_W:
        if (event.type() == QEvent::KeyPress)
            m_xRotationFactor -= 1;
        else
            m_xRotationFactor += 1;
        break;

    case Qt::Key_S:
        if (event.type() == QEvent::KeyPress)
            m_xRotationFactor += 1;
        else
            m_xRotationFactor -= 1;
        break;

    case Qt::Key_A:
        if (event.type() == QEvent::KeyPress)
            m_yRotationFactor += 1;
        else
            m_yRotationFactor -= 1;
        break;

    case Qt::Key_D:
        if (event.type() == QEvent::KeyPress)
            m_yRotationFactor -= 1;
        else
            m_yRotationFactor += 1;
        break;
    }
}

void QtUserInputMeshController::onMouseEvent(QMouseEvent) {
    /*if (event.button() == Qt::RightButton) {
        if (event.type() == QEvent::MouseButtonPress)
            qDebug("Right mouse button pressed at %d; %d", m_userInput.pointerX(), m_userInput.pointerY());
        else
            qDebug() << "Right mouse button released";
    }*/
}
