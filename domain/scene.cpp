#include <memory>
#include "glm/glm.hpp"
#include "scene.h"
#include "domain/transformationcomponent.h"

Scene::Scene(GameObjectsHierarchyContainer& gameObjectsHierarchyContainer) :
    m_gameObjectsHierarchyContainer(gameObjectsHierarchyContainer)
{
    m_rootGameObject = std::make_shared<GameObject>("root");
    m_gameObjectsHierarchyContainer.setRootGameObject(m_rootGameObject);
    m_rootGameObject->attachComponent(
                std::shared_ptr<TransformationComponent>(
                    new TransformationComponent("transform", glm::vec3(0), glm::identity<glm::quat>(), glm::vec3(1))
                )
    );
}

Scene::~Scene()
{
    m_gameObjectsHierarchyContainer.setRootGameObject(std::shared_ptr<GameObject>());
}

void Scene::onUpdate()
{
    m_rootGameObject->onUpdate();
    m_gameObjectsHierarchyContainer.onUpdate();
}
