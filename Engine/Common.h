#ifndef COMMON_H
#define COMMON_H

#include <QObject>

#define DECLARE_MEMBER(type, name) \
protected: \
    type m##name; \
\
public: \
    inline const type &get##name(void) const { return m##name; } \
\
public: \
    inline type &get##name##_nonConst(void) { return m##name; } \
\
public: \
    inline void set##name(const type &var) { m##name = var; }

namespace Canavar {
namespace Engine {

class Model;

enum class ShaderType { //
    None,
    ModelColoredShader,
    ModelTexturedShader,
    SkyShader,
    TerrainShader,
    BlurShader,
    PostProcessShader,
    ScreenShader,
    MeshInfoShader,
    NozzleEffectShader,
    FirecrackerEffectShader
};

enum class RenderPass { //
    Default = 0x00,
    MeshInfo = 0x01,
    Custom = 0x02,
};

Q_DECLARE_FLAGS(RenderPasses, RenderPass);

extern const float CUBE[108];
extern const float QUAD[24];

} // namespace Engine
} // namespace Canavar

Q_DECLARE_OPERATORS_FOR_FLAGS(Canavar::Engine::RenderPasses)

#endif // COMMON_H
