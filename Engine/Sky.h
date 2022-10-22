#ifndef SKY_H
#define SKY_H

#include "CameraManager.h"
#include "LightManager.h"
#include "ShaderManager.h"

#include <QOpenGLExtraFunctions>

namespace Canavar {
namespace Engine {

class Sky : public Node, protected QOpenGLExtraFunctions
{
private:
    explicit Sky(QObject *parent = nullptr);

public:
    static Sky *instance();

    void render();

private:
    ShaderManager *mShaderManager;
    CameraManager *mCameraManager;
    LightManager *mLightManager;

    // OpenGL Stuff
    QVector<unsigned int> mVertices;
    unsigned int mVAO;
    unsigned int mVBO;

    // Model
    QVector3D A, B, C, D, E, F, G, H, I;
    QVector3D Z;

    DECLARE_MEMBER(bool, Enabled)
    DECLARE_MEMBER(float, Albedo)
    DECLARE_MEMBER(float, Turbidity)
    DECLARE_MEMBER(float, NormalizedSunY)
};

} // namespace Engine
} // namespace Canavar

#endif // SKY_H
