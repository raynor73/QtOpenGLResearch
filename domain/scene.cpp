#include <memory>
#include "glm/glm.hpp"
#include "scene.h"
#include "domain/transformationcomponent.h"

Scene::Scene() : m_rootGameObject("root")
{
    m_rootGameObject.attachComponent(
                std::static_pointer_cast<GameObjectComponent>(
                    std::shared_ptr<TransformationComponent>(
                        new TransformationComponent("transform", glm::vec3(0), glm::identity<glm::quat>(), glm::vec3(1))
                    )
                )
    );
}

void Scene::onUpdate()
{
    m_rootGameObject.onUpdate();
}
