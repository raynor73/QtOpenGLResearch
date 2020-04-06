#ifndef MESHCOMPONENT_H
#define MESHCOMPONENT_H

#include <string>
#include <memory>
#include "domain/mesh.h"
#include "domain/game_object/gameobjectcomponent.h"

class MeshComponent : public GameObjectComponent
{
public:
    MeshComponent(const std::string& componentName, const std::string& meshName, std::shared_ptr<Mesh> mesh);

    std::shared_ptr<const Mesh> mesh() { return m_mesh; };
    const std::string meshName() { return m_meshName; };

    virtual const std::string& type() const override;
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) override;

    static const std::string TYPE_NAME;

private:
    std::string m_meshName;
    std::shared_ptr<Mesh> m_mesh;
};

#endif // MESHCOMPONENT_H
