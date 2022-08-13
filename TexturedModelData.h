#ifndef TEXTUREDMODELDATA_H
#define TEXTUREDMODELDATA_H

#include "Mesh.h"
#include "TexturedMaterial.h"
#include "TexturedModelDataNode.h"

#include <QObject>

class TexturedModelData : public QObject
{
    Q_OBJECT
public:
    explicit TexturedModelData(const QString &name, QObject *parent = nullptr);

    void addMesh(Mesh *mesh);
    void addMaterial(TexturedMaterial *material);

    TexturedModelDataNode *rootNode() const;
    void setRootNode(TexturedModelDataNode *newRootNode);

    const QVector<Mesh *> &meshes() const;
    const QString &name() const;
    const QVector<TexturedMaterial *> &materials() const;

    void render();

private:
    QString mName;
    TexturedModelDataNode *mRootNode;
    QVector<Mesh *> mMeshes;
    QVector<TexturedMaterial *> mMaterials;
};

#endif // TEXTUREDMODELDATA_H