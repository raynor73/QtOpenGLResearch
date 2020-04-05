#include <sstream>
#include "domain/exception.h"
#include "domain/game_object/gameobject.h"
#include "domain/transformationcomponent.h"
#include "directionallight.h"

const std::string DirectionalLight::TYPE_NAME = "DirectionalLight";

DirectionalLight::DirectionalLight(const std::string& name, const glm::vec3& color) :
    GameObjectComponent(name),
    m_color(color)
{}

glm::vec3 DirectionalLight::direction() const
{
    auto gameObject = m_gameObject.lock();
    if (!gameObject) {
        std::stringstream msgBuilder;
        msgBuilder << "Component " << m_name << " of type " << TYPE_NAME << " has no parent game object";
        throw Exception(msgBuilder.str());
    }
    std::shared_ptr<TransformationComponent> transform = std::static_pointer_cast<TransformationComponent>(
                gameObject->findComponent(TransformationComponent::TYPE_NAME)
    );
    if (!transform) {
        std::stringstream msgBuilder;
        msgBuilder << "Game object " << gameObject->name() << " has no transform component";
        throw Exception(msgBuilder.str());
    }
    glm::vec3 direction = Constants::DEFAULT_FORWARD_DIRECTION;
    direction = transform->rotation() * direction;
    return direction;
}

const std::string& DirectionalLight::type() const
{
    return TYPE_NAME;
}

std::shared_ptr<GameObjectComponent> DirectionalLight::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(new DirectionalLight(cloneName, m_color));
}

