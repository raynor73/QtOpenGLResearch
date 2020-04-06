#include "materialcomponent.h"

const std::string MaterialComponent::TYPE_NAME = "MaterialComponent";

MaterialComponent::MaterialComponent(
        const std::string& name,
        const std::string& textureName,
        const glm::vec4& diffuseColor,
        bool isDoubleSided,
        bool isWireframe,
        bool isUnlit,
        bool isTranslucent,
        bool castShadows,
        bool receiveShadows,
        bool isSprite
) :
    GameObjectComponent(name),
    m_textureName(textureName),
    m_diffuseColor(diffuseColor),
    m_isDoubleSided(isDoubleSided),
    m_isWireframe(isWireframe),
    m_isUnlit(isUnlit),
    m_isTranslucent(isTranslucent),
    m_castShadows(castShadows),
    m_receiveShadows(receiveShadows),
    m_isSprite(isSprite)
{}

const std::string& MaterialComponent::type() const
{
    return TYPE_NAME;
}

std::shared_ptr<GameObjectComponent> MaterialComponent::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(
                new MaterialComponent(
                    cloneName,
                    m_textureName,
                    m_diffuseColor,
                    m_isDoubleSided,
                    m_isWireframe,
                    m_isUnlit,
                    m_isTranslucent,
                    m_castShadows,
                    m_receiveShadows,
                    m_isSprite
                )
    );
}

