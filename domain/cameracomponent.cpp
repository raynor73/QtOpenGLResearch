#include "cameracomponent.h"

CameraComponent::CameraComponent(const std::string& name, float zNear, float zFar) :
    GameObjectComponent(name),
    m_zNear(zNear),
    m_zFar(zFar)
{}

void CameraComponent::setLayerNames(const std::vector<std::string>& layerNames)
{
    m_layerNames.clear();
    for (auto it = layerNames.begin(); it != layerNames.end(); ++it) {
        m_layerNames.push_back(*it);
    }
}
