#ifndef WATER_H
#define WATER_H

#include "CameraManager.h"
#include "Framebuffer.h"
#include "Haze.h"
#include "ShaderManager.h"

#include <QObject>
#include <QOpenGLExtraFunctions>
#include <QOpenGLVertexArrayObject>
#include <QVector2D>
#include <QVector3D>

class Water : public QObject, protected QOpenGLExtraFunctions
{
    Q_OBJECT
private:
    explicit Water(QObject *parent = nullptr);

    struct Vertex {
        QVector3D position;
        QVector3D normal;
        QVector2D texture;
    };

public:
    static Water *instance();
    void create(int numberOfVerticesOnEdge = 3, float width = 1024.0f);
    void render(float ifps);
    void resize(int width, int height);

    void setHaze(Haze *newHaze);

    float waterHeight() const;

    Framebuffer *reflectionFramebuffer() const;
    Framebuffer *refractionFramebuffer() const;

private:
    void createFramebuffers();
    void deleteFramebuffers();

private:
    ShaderManager *mShaderManager;
    CameraManager *mCameraManager;
    LightManager *mLightManager;
    Haze *mHaze;

    QVector<Vertex> mVertices;
    QVector<unsigned int> mIndices;
    QOpenGLVertexArrayObject *mVAO;
    unsigned int mVBO;
    unsigned int mEBO;

    float mWaterHeight;
    float mWaveSpeed;
    float mTimeElapsed;

    Framebuffer *mReflectionFramebuffer;
    Framebuffer *mRefractionFramebuffer;
    FramebufferFormat mFramebufferFormat;

    QMatrix4x4 mTransformation;

    int mNumberOfVerticesOnEdge;
};

#endif // WATER_H