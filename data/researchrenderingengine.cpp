#include <QOpenGLFunctions_4_5_Core>
#include "researchrenderingengine.h"

void hierarchyReportCallback(GameObject& gameObject, void* userData)
{

}

ResearchRenderingEngine::ResearchRenderingEngine(GameObjectsHierarchyContainer& gameObjectsHierarchyContainer) :
    m_gameObjectsHierarchyContainer(gameObjectsHierarchyContainer)
{
    m_gameObjectsHierarchyContainer.registerReportCallback(hierarchyReportCallback, this);
}

ResearchRenderingEngine::~ResearchRenderingEngine()
{
    m_gameObjectsHierarchyContainer.unregisterReportCallbck(hierarchyReportCallback);
}

void ResearchRenderingEngine::addMesh(const std::string& name, const Mesh& mesh)
{

}

void ResearchRenderingEngine::removeMesh(const std::string& name)
{

}

void ResearchRenderingEngine::addTexture(const std::string& name, const Texture& texture)
{

}

void ResearchRenderingEngine::removeTexture(const std::string& name)
{

}

void ResearchRenderingEngine::addTextureArray(const std::string& name, const TextureArray& textureArray)
{

}

void ResearchRenderingEngine::removeTextureArray(const std::string& name)
{

}

void ResearchRenderingEngine::render()
{

}
