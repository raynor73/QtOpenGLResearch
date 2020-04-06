#include <sstream>
#include "domain/exception.h"
#include "meshrenderercomponent.h"

const std::string MeshRendererComponent::TYPE_NAME = "TransformationComponent";

MeshRendererComponent::MeshRendererComponent(const std::string& name) : GameObjectComponent(name) {}

void MeshRendererComponent::render(
        const ShaderProgramInfo& shaderProgramInfo,
        CameraComponent& camera,
        const LightSources& lightSources
)
{
    auto gameObject = m_gameObject.lock();
    if (!gameObject) {
        std::stringstream msgBuilder;
        msgBuilder << "Component " << m_name << " not attached to game object";
        throw Exception(msgBuilder.str());
    }

}

const std::string& MeshRendererComponent::type() const
{
    return TYPE_NAME;
}

std::shared_ptr<GameObjectComponent> MeshRendererComponent::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(new MeshRendererComponent(cloneName));
}

