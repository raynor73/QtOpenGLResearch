#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "glm/glm.hpp"
#include "domain/constants.h"
#include "domain/game_object/gameobjectcomponent.h"

class DirectionalLight : public GameObjectComponent
{
public:
    DirectionalLight(const std::string& name, const glm::vec3& color);

    const glm::vec3& color() const { return m_color; };
    void setColor(const glm::vec3& color) { m_color = color; };

    glm::vec3 direction() const;

    virtual const std::string& type() const override;
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) override;

    static const std::string TYPE_NAME;

private:
    glm::vec3 m_color;
};

#endif // DIRECTIONALLIGHT_H
