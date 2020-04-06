#ifndef MATERIALCOMPONENT_H
#define MATERIALCOMPONENT_H

#include <string>
#include "glm/glm.hpp"
#include "domain/game_object/gameobjectcomponent.h"

class MaterialComponent : public GameObjectComponent
{
public:
    MaterialComponent(
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
    );

    const std::string& textureName() const { return m_textureName; }
    void setTextureName(const std::string& textureName) { m_textureName = textureName; }
    const glm::vec4& diffuseColor() const { return m_diffuseColor; }
    void setDiffuseColor(const glm::vec4& diffuseColor) { m_diffuseColor = diffuseColor; }
    bool isDoubleSided() const { return m_isDoubleSided; }
    void setDoubleSided(bool isDoubleSided) { m_isDoubleSided = isDoubleSided; }
    bool isWireframe() const { return m_isWireframe; }
    void setWireframe(bool isWireframe) { m_isWireframe = isWireframe; }
    bool isUnlit() const { return m_isUnlit; }
    void setUnlit(bool isUnlit) { m_isUnlit = isUnlit; }
    bool isTranslucent() const { return m_isTranslucent; }
    void setTranslucent(bool isTranslucent) { m_isTranslucent = isTranslucent; }
    bool castShadows() const { return m_castShadows; }
    void setCastShadows(bool castShadows) { m_castShadows = castShadows; }
    bool receiveShadows() const { return m_receiveShadows; }
    void setReceiveShadows(bool receiveShadows) { m_receiveShadows = receiveShadows; }
    bool isSprite() const { return m_isSprite; }
    void setSprite(bool isSprite) { m_isSprite = isSprite; }

    virtual const std::string& type() const override;
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) override;

    static const std::string TYPE_NAME;

private:
    std::string m_textureName;
    glm::vec4 m_diffuseColor;
    bool m_isDoubleSided;
    bool m_isWireframe;
    bool m_isUnlit;
    bool m_isTranslucent;
    bool m_castShadows;
    bool m_receiveShadows;
    bool m_isSprite;
};

#endif // MATERIALCOMPONENT_H