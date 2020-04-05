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
    data/framebufferinfo.cpp \
    data/iboinfo.cpp \
    data/lightsources.cpp \
    data/meshrenderercomponent.cpp \
    data/openglerrordetector.cpp \
    data/openglgeometryrepository.cpp \
    data/openglshadersrepository.cpp \
    data/qtdisplaymetricsrepository.cpp \
    data/qttimerepository.cpp \
    data/qtuserinputmeshcontroller.cpp \
    data/researchrenderingengine.cpp \
    data/shaderprograminfo.cpp \
    data/userinput.cpp \
    data/vaoinfo.cpp \
    domain/assets/texturearraydata.cpp \
    domain/assets/texturedata.cpp \
    domain/assets/texturerepository2.cpp \
    domain/assets/texturesrepository.cpp \
    domain/cameracomponent.cpp \
    domain/displaymetricsrepository.cpp \
    domain/exception.cpp \
    domain/game_object/gameobjectcomponent.cpp \
    domain/game_object/gameobject.cpp \
    domain/gameobjectshierarchycontainer.cpp \
    domain/geometryrepository.cpp \
    domain/light_sources/directionallight.cpp \
    domain/mesh.cpp \
    domain/meshcontroller.cpp \
    domain/renderingengine.cpp \
    domain/scene.cpp \
    domain/timerepository.cpp \
    domain/transformationcomponent.cpp \
    domain/vertex.cpp \
    main.cpp \
    mainwindow.cpp \
    ui/openglwidget.cpp \
    ui/openglwidget2.cpp \
    utils.cpp

HEADERS += \
    data/assets/opengltexturesrepository.h \
    data/assets/textureinfo.h \
    data/framebufferinfo.h \
    data/iboinfo.h \
    data/lightsources.h \
    data/meshrenderercomponent.h \
    data/openglerrordetector.h \
    data/openglgeometryrepository.h \
    data/openglshadersrepository.h \
    data/qtdisplaymetricsrepository.h \
    data/qttimerepository.h \
    data/qtuserinputmeshcontroller.h \
    data/researchrenderingengine.h \
    data/shaderprograminfo.h \
    data/userinput.h \
    data/vaoinfo.h \
    domain/assets/texturearraydata.h \
    domain/assets/texturedata.h \
    domain/assets/texturerepository2.h \
    domain/assets/texturesrepository.h \
    domain/cameracomponent.h \
    domain/constants.h \
    domain/displaymetricsrepository.h \
    domain/exception.h \
    domain/game_object/gameobjectcomponent.h \
    domain/game_object/gameobject.h \
    domain/gameobjectshierarchycontainer.h \
    domain/geometryrepository.h \
    domain/light_sources/directionallight.h \
    domain/mesh.h \
    domain/meshcontroller.h \
    domain/renderingengine.h \
    domain/scene.h \
    domain/timerepository.h \
    domain/transformationcomponent.h \
    domain/vertex.h \
    mainwindow.h \
    ui/openglwidget.h \
    ui/openglwidget2.h \
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

macx: LIBS += -L$$PWD/../../local/lib/ -lassimp.5.0.0

INCLUDEPATH += $$PWD/../../local/include
DEPENDPATH += $$PWD/../../local/include
