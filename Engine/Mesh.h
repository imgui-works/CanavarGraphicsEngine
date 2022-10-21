#ifndef MESH_H
#define MESH_H

#include "Common.h"
#include "Material.h"

#include <QObject>
#include <QOpenGLExtraFunctions>
#include <QOpenGLVertexArrayObject>
#include <QVector3D>

namespace Canavar {
namespace Engine {

class CameraManager;
class ShaderManager;
class LightManager;

class Camera;
class Sun;

class Mesh : public QObject, protected QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    struct Vertex {
        QVector3D position;
        QVector3D normal;
        QVector2D texture;
        QVector3D tangent;
        QVector3D bitangent;
        int boneIDs[4];
        float weights[4];
    };

    struct AABB {
        QVector3D min;
        QVector3D max;

        QVector3D getCenter() const { return (min + max) / 2.0f; }
    };

    explicit Mesh(QObject *parent = nullptr);
    virtual ~Mesh();

    void addVertex(const Vertex &vertex);
    void addIndex(unsigned int index);
    void setMaterial(Material *material);
    void create();

    const AABB &aABB() const;
    void setAABB(const AABB &newAABB);

    const QString &name() const;
    void setName(const QString &newName);

    unsigned int id() const;
    void setId(unsigned int newId);

    void render(const RenderParameters &parameters);

private:
    QOpenGLVertexArrayObject *mVAO;
    unsigned int mEBO;
    unsigned int mVBO;

    QVector<Vertex> mVertices;
    QVector<unsigned int> mIndices;
    Material *mMaterial;
    AABB mAABB;
    QString mName;
    unsigned int mId;

    // For rendering
    ShaderManager *mShaderManager; // Might be static
    CameraManager *mCameraManager; // Might be static
    LightManager *mLightManager;   // Might be static
};

} // namespace Engine
} // namespace Canavar

#endif // MESH_H