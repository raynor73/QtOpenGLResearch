#ifndef RESEARCHRENDERINGENGINE_H
#define RESEARCHRENDERINGENGINE_H

#include <stack>
#include "domain/renderingengine.h"
#include "domain/gameobjectshierarchycontainer.h"
#include "data/opengl_state/openglstate.h"
#include "data/openglerrordetector.h"

class ResearchRenderingEngine : public RenderingEngine
{
public:
    ResearchRenderingEngine(
            OpenGLErrorDetector& openGLErrorDetector,
            GameObjectsHierarchyContainer& gameObjectsHierarchyContainer
    );
    ~ResearchRenderingEngine();

    virtual void addMesh(const std::string& name, const Mesh& mesh) override;
    virtual void removeMesh(const std::string& name) override;
    virtual void addTexture(const std::string& name, const Texture& texture) override;
    virtual void removeTexture(const std::string& name) override;
    virtual void addTextureArray(const std::string& name, const TextureArray& textureArray) override;
    virtual void removeTextureArray(const std::string& name) override;
    virtual void render() override;

private:
    OpenGLErrorDetector& m_openGLErrorDetector;
    GameObjectsHierarchyContainer& m_gameObjectsHierarchyContainer;
    std::stack<OpenGLState> m_openGLStateStack;

    void pushOpenGLState(const OpenGLState& state);
    void popOpenGLState();
    void applyOpenGLState(const OpenGLState& state);

    friend void hierarchyReportCallback(GameObject& gameObject, void* userData);
};

#endif // RESEARCHRENDERINGENGINE_H
