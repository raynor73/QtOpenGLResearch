#ifndef GAMEOBJECTSHIERARCHYCONTAINER_H
#define GAMEOBJECTSHIERARCHYCONTAINER_H

#include <map>
#include <memory>
#include "domain/game_object/gameobject.h"

class GameObjectsHierarchyContainer
{
public:
    void setRootGameObject(std::shared_ptr<GameObject> rootGameObject) { m_rootGameObject = rootGameObject; }

    void registerReportCallback(void (*callback)(GameObject&, void*), void* userData);
    void unregisterReportCallbck(void (*callback)(GameObject&, void*));
    void onUpdate();

private:
    std::shared_ptr<GameObject> m_rootGameObject;
    std::map<void (*)(GameObject&, void*), void*> m_reportCallbacksWithUserData;
};

#endif // GAMEOBJECTSHIERARCHYCONTAINER_H
