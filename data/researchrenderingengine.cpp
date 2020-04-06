#include <QOpenGLFunctions_4_5_Core>
#include "domain/exception.h"
#include "researchrenderingengine.h"

void hierarchyReportCallback(GameObject& gameObject, void* userData)
{

}

ResearchRenderingEngine::ResearchRenderingEngine(
        DisplayMetricsRepository& displayMetricsRepository,
        OpenGLErrorDetector& openGLErrorDetector,
        GameObjectsHierarchyContainer& gameObjectsHierarchyContainer
) :
    m_displayMetricsRepository(displayMetricsRepository),
    m_openGLErrorDetector(openGLErrorDetector),
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
    glClearColor(0, 0.5, 0, 1);

    pushOpenGLState({
                        .viewport = {
                            .x = 0,
                            .y = 0,
                            .width = m_displayMetricsRepository.width(),
                            .height = m_displayMetricsRepository.height()
                        },
                        .scissor = {
                            .x = 0,
                            .y = 0,
                            .width = m_displayMetricsRepository.width(),
                            .height = m_displayMetricsRepository.height()
                        },
                        .blend = false,
                        .blendFunction = { GL_ONE, GL_ONE },
                        .depthMask = true,
                        .depthFunction = GL_LESS
    });

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    popOpenGLState();
}

void ResearchRenderingEngine::pushOpenGLState(const OpenGLState& state)
{
    applyOpenGLState(state);
    m_openGLStateStack.push(state);
}

void ResearchRenderingEngine::popOpenGLState()
{
    m_openGLStateStack.pop();
    if (m_openGLStateStack.size() > 0) {
        //throw Exception("No state to apply in OpenGL state stack");
        applyOpenGLState(m_openGLStateStack.top());
    }
}

void ResearchRenderingEngine::applyOpenGLState(const OpenGLState& state)
{
    glViewport(state.viewport.x, state.viewport.y, state.viewport.width, state.viewport.height);
    glScissor(state.scissor.x, state.scissor.y, state.scissor.width, state.scissor.height);
    if (state.blend) {
        glEnable(GL_BLEND);
    } else {
        glDisable(GL_BLEND);
    }
    glBlendFunc(state.blendFunction.sFactor, state.blendFunction.dFactor);
    glDepthMask(state.depthMask);
    glDepthFunc(state.depthFunction);

    m_openGLErrorDetector.dispatchOpenGLErrors("ResearchRenderingEngine::applyOpenGLState");
}

