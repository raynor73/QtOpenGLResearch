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

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setVersion(4, 1);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    m_openglWidget = new OpenGLWidget(this, 60);
    m_openglWidget->setGeometry(0, 0, displayWidth, displayHeight);
}

MainWindow::~MainWindow()
{
    delete m_openglWidget;
    delete ui;
}

