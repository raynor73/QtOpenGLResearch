#ifndef RESEARCHRENDERINGENGINE_H
#define RESEARCHRENDERINGENGINE_H

#include "domain/renderingengine.h"
#include "domain/gameobjectshierarchycontainer.h"

class ResearchRenderingEngine : public RenderingEngine
{
public:
    ResearchRenderingEngine(GameObjectsHierarchyContainer& gameObjectsHierarchyContainer);
    ~ResearchRenderingEngine();

    virtual void addMesh(const std::string& name, const Mesh& mesh) override;
    virtual void removeMesh(const std::string& name) override;
    virtual void addTexture(const std::string& name, const Texture& texture) override;
    virtual void removeTexture(const std::string& name) override;
    virtual void addTextureArray(const std::string& name, const TextureArray& textureArray) override;
    virtual void removeTextureArray(const std::string& name) override;
    virtual void render() override;

private:
    GameObjectsHierarchyContainer& m_gameObjectsHierarchyContainer;

    friend void hierarchyReportCallback(GameObject& gameObject, void* userData);
};

#endif // RESEARCHRENDERINGENGINE_H
