#ifndef TRANSFORMATIONCOMPONENT_H
#define TRANSFORMATIONCOMPONENT_H

#include "glm/glm.hpp"
#include "glm/ext/quaternion_float.hpp"
#include "domain/game_object/gameobjectcomponent.h"

class TransformationComponent : public GameObjectComponent
{
public:
    explicit TransformationComponent(
            const std::string& name,
            const glm::vec3& position,
            const glm::quat& rotation,
            const glm::vec3& scale
    );

    const glm::vec3& localPosition() const { return m_position; }
    const glm::quat& localRotation() const { return m_rotation; }
    const glm::vec3& localScale() const { return m_scale; }

    const glm::vec3& position();
    void setPosition(const glm::vec3& position);
    const glm::quat& rotation();
    void setRotation(const glm::quat& rotation);
    const glm::vec3& scale();
    void setScale(const glm::vec3& scale);

    virtual const std::string& type() const override { return TYPE_NAME; };
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) override;

    static const std::string TYPE_NAME;

private:
    bool m_isDirty = false;

    glm::vec3 m_position;
    glm::quat m_rotation;
    glm::vec3 m_scale;

    glm::vec3 m_finalPosition;
    glm::quat m_finalRotation;
    glm::vec3 m_finalScale;

    void setDirty();
    void calculateFinalTransformation();
};

#endif // TRANSFORMATIONCOMPONENT_H
