#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "data/qtdisplaymetricsrepository.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QtDisplayMetricsRepository displayMetricsRepository;
    int displayWidth = displayMetricsRepository.width();
    int displayHeight = displayMetricsRepository.height();
    setFixedSize(displayWidth, displayHeight);

    m_openglWidget = new OpenGLWidget(this, 60);
    m_openglWidget->setGeometry(0, 0, displayWidth, displayHeight);
}

MainWindow::~MainWindow()
{
    delete ui;
}

