QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


include(Dependencies/qtimgui/qtimgui.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

HEADERS += \
    Camera.h \
    CameraManager.h \
    Controller.h \
    DirectionalLight.h \
    DummyCamera.h \
    Framebuffer.h \
    FreeCamera.h \
    Haze.h \
    Helper.h \
    Light.h \
    LightManager.h \
    Mesh.h \
    Model.h \
    ModelData.h \
    ModelDataNode.h \
    Node.h \
    NodeManager.h \
    NozzleEffect.h \
    PointLight.h \
    Quad.h \
    RandomGenerator.h \
    RendererManager.h \
    Shader.h \
    ShaderManager.h \
    Simulator/Aircraft.h \
    Simulator/AircraftController.h \
    Simulator/Converter.h \
    Sky.h \
    SkyBox.h \
    SpotLight.h \
    Terrain.h \
    Texture.h \
    TextureMaterial.h \
    Window.h

SOURCES += \
    Camera.cpp \
    CameraManager.cpp \
    Controller.cpp \
    DirectionalLight.cpp \
    DummyCamera.cpp \
    Framebuffer.cpp \
    FreeCamera.cpp \
    Haze.cpp \
    Helper.cpp \
    Light.cpp \
    LightManager.cpp \
    Main.cpp \
    Mesh.cpp \
    Model.cpp \
    ModelData.cpp \
    ModelDataNode.cpp \
    Node.cpp \
    NodeManager.cpp \
    NozzleEffect.cpp \
    PointLight.cpp \
    Quad.cpp \
    RandomGenerator.cpp \
    RendererManager.cpp \
    Shader.cpp \
    ShaderManager.cpp \
    Simulator/Aircraft.cpp \
    Simulator/AircraftController.cpp \
    Simulator/Converter.cpp \
    Sky.cpp \
    SkyBox.cpp \
    SpotLight.cpp \
    Terrain.cpp \
    Texture.cpp \
    TextureMaterial.cpp \
    Window.cpp

INCLUDEPATH += $$PWD/Dependencies/Eigen/
INCLUDEPATH += $$PWD/Dependencies/Assimp/include
DEPENDPATH += $$PWD/Dependencies/Assimp/include

LIBS += -L$$PWD/Dependencies/Assimp/lib/ -lassimp-vc142-mt

LIBS += -L$$PWD/Dependencies/JSBSim/lib/ -lJSBSim
LIBS += -lws2_32

INCLUDEPATH += $$PWD/Dependencies/JSBSim/include
DEPENDPATH += $$PWD/Dependencies/JSBSim/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Dependencies/JSBSim/lib/JSBSim.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/Dependencies/JSBSim/lib/libJSBSim.a
