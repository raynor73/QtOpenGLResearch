QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    data/assets/opengltexturesrepository.cpp \
    data/assets/textureinfo.cpp \
    data/iboinfo.cpp \
    data/openglerrordetector.cpp \
    data/openglgeometryrepository.cpp \
    data/openglshadersrepository.cpp \
    data/qtdisplaymetricsrepository.cpp \
    data/qtuserinputmeshcontroller.cpp \
    data/shaderprograminfo.cpp \
    data/userinput.cpp \
    data/vaoinfo.cpp \
    domain/assets/texturesrepository.cpp \
    domain/displaymetricsrepository.cpp \
    domain/exception.cpp \
    domain/geometryrepository.cpp \
    domain/mesh.cpp \
    domain/meshcontroller.cpp \
    domain/vertex.cpp \
    main.cpp \
    mainwindow.cpp \
    ui/openglwidget.cpp \
    utils.cpp

HEADERS += \
    data/assets/opengltexturesrepository.h \
    data/assets/textureinfo.h \
    data/iboinfo.h \
    data/openglerrordetector.h \
    data/openglgeometryrepository.h \
    data/openglshadersrepository.h \
    data/qtdisplaymetricsrepository.h \
    data/qtuserinputmeshcontroller.h \
    data/shaderprograminfo.h \
    data/userinput.h \
    data/vaoinfo.h \
    domain/assets/texturesrepository.h \
    domain/displaymetricsrepository.h \
    domain/exception.h \
    domain/geometryrepository.h \
    domain/mesh.h \
    domain/meshcontroller.h \
    domain/vertex.h \
    mainwindow.h \
    ui/openglwidget.h \
    utils.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourvces.qrc

DISTFILES += \
    resources/shaders/fragmentShader.glsl \
    resources/shaders/vertexShader.glsl

macx: LIBS += -L$$PWD/../../local/lib/ -lode.0.16.1

INCLUDEPATH += $$PWD/../../local/include
DEPENDPATH += $$PWD/../../local/include
