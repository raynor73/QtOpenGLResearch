#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "ui/openglwidget2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    OpenGLWidget2* m_openglWidget;
};
#endif // MAINWINDOW_H
