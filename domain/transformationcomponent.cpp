#include "transformationcomponent.h"
#include <sstream>
#include "domain/exception.h"
#include "domain/game_object/gameobject.h"

const std::string TransformationComponent::TYPE_NAME = "TransformationComponent";

TransformationComponent::TransformationComponent(
        const std::string& name,
        const glm::vec3& position,
        const glm::quat& rotation,
        const glm::vec3& scale
) :
    GameObjectComponent(name),
    m_position(position),
    m_rotation(rotation),
    m_scale(scale)
{}

std::shared_ptr<GameObjectComponent> TransformationComponent::clone()
{
    std::stringstream cloneNameBuilder;
    cloneNameBuilder << m_name << nextCloneNamePostfix();
    return clone(cloneNameBuilder.str());
}

std::shared_ptr<GameObjectComponent> TransformationComponent::clone(const std::string& cloneName)
{
    return std::shared_ptr<GameObjectComponent>(
                new TransformationComponent(cloneName, m_position, m_rotation, m_scale)
    );
}

const glm::vec3& TransformationComponent::position()
{
    calculateFinalTransformation();
    return m_finalPosition;
}

void TransformationComponent::setPosition(const glm::vec3& position)
{
    setDirty();
    m_position = position;
}

const glm::quat& TransformationComponent::rotation()
{
    calculateFinalTransformation();
    return m_finalRotation;
}

void TransformationComponent::setRotation(const glm::quat &rotation)
{
    setDirty();
    m_rotation = rotation;
}

const glm::vec3& TransformationComponent::scale()
{
    calculateFinalTransformation();
    return m_finalScale;
}

void TransformationComponent::setScale(const glm::vec3 &scale)
{
    setDirty();
    m_scale = scale;
}

void TransformationComponent::setDirty()
{
    auto gameObject = m_gameObject.lock();
    if (!gameObject) {
        std::stringstream msgBuilder;
        msgBuilder << "Component " << m_name << " of type " << TYPE_NAME << " has no parent game object";
        throw Exception(msgBuilder.str());
    }

    auto children = gameObject->children();
    for (auto it = children.begin(); it != children.end(); ++it) {
        std::shared_ptr<TransformationComponent> childTransform =
                std::static_pointer_cast<TransformationComponent>(it->second->findComponent(TYPE_NAME));
        if (!childTransform) {
            std::stringstream msgBuilder;
            msgBuilder << "Game object " << it->second->name() << " has no transform component";
            throw Exception(msgBuilder.str());
        }
        childTransform->setDirty();
    }

    m_isDirty = true;
}

void TransformationComponent::calculateFinalTransformation()
{
    if (m_isDirty) {
        auto gameObject = m_gameObject.lock();
        if (!gameObject) {
            std::stringstream msgBuilder;
            msgBuilder << "Component " << m_name << " of type " << TYPE_NAME << " has no parent game object";
            throw Exception(msgBuilder.str());
        }
        auto parentGameObject = gameObject->parent();
        if (parentGameObject) {
            std::shared_ptr<TransformationComponent> parentTransform =
                    std::static_pointer_cast<TransformationComponent>(parentGameObject->findComponent(TYPE_NAME));
            if (!parentTransform) {
                std::stringstream msgBuilder;
                msgBuilder << "Parent game object" << parentGameObject->name() << " has no transform component";
                throw Exception(msgBuilder.str());
            }

            m_finalRotation = m_rotation * parentTransform->rotation();

            m_finalScale = m_scale * parentTransform->scale();

            m_finalPosition = parentTransform->rotation() * m_position;
            m_finalPosition += m_position;
        } else {
            m_finalPosition = m_position;
            m_finalRotation = m_rotation;
            m_finalScale = m_scale;
        }
        m_isDirty = false;
    }
}
