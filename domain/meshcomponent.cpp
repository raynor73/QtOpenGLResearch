#include "meshcomponent.h"

const std::string MeshComponent::TYPE_NAME = "MeshComponent";

MeshComponent::MeshComponent(
        const std::string& componentName,
        const std::string& meshName,
        std::shared_ptr<Mesh> mesh
) : GameObjectComponent(componentName), m_meshName(meshName), m_mesh(mesh)
{}

const std::string& MeshComponent::type() const
{
    return TYPE_NAME;
}

std::shared_ptr<GameObjectComponent> MeshComponent::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(
                new MeshComponent(cloneName, m_meshName, m_mesh)
    );
}
