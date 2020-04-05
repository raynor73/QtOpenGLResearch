#include <queue>
#include <memory>
#include "domain/game_object/gameobject.h"
#include "gameobjectshierarchycontainer.h"

GameObjectsHierarchyContainer::GameObjectsHierarchyContainer(GameObject& rootGameObject) :
    m_rootGameObject(rootGameObject)
{}

void GameObjectsHierarchyContainer::registerReportCallback(void (*callback)(GameObject&, void*), void* userData)
{
    m_reportCallbacksWithUserData[callback] = userData;
}

void GameObjectsHierarchyContainer::unregisterReportCallbck(void (*callback)(GameObject&, void*))
{
    m_reportCallbacksWithUserData.erase(callback);
}

void GameObjectsHierarchyContainer::onUpdate()
{
    std::queue<std::shared_ptr<GameObject>> gameObjectsQueue;
    gameObjectsQueue.push(std::make_shared<GameObject>(m_rootGameObject));

    do {
        auto currentGameObject = gameObjectsQueue.front();
        gameObjectsQueue.pop();
        for (
             auto callbacksIterator = m_reportCallbacksWithUserData.begin();
             callbacksIterator != m_reportCallbacksWithUserData.end();
             ++callbacksIterator
        ) {
            (*callbacksIterator->first)(*currentGameObject, callbacksIterator->second);
        }

        auto children = currentGameObject->children();
        for (auto childrenIterator = children.begin(); childrenIterator != children.end(); ++childrenIterator) {
            gameObjectsQueue.push(childrenIterator->second);
        }
    } while (!gameObjectsQueue.empty());
}
