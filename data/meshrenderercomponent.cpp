#include "meshrenderercomponent.h"

const std::string MeshRendererComponent::TYPE_NAME = "TransformationComponent";

MeshRendererComponent::MeshRendererComponent(const std::string& name) : GameObjectComponent(name)
{

}

const std::string& MeshRendererComponent::type() const
{
    return TYPE_NAME;
}

std::shared_ptr<GameObjectComponent> MeshRendererComponent::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(new MeshRendererComponent(cloneName));
}

