#ifndef GAMEOBJECTSHIERARCHYCONTAINER_H
#define GAMEOBJECTSHIERARCHYCONTAINER_H

#include <map>
#include "domain/game_object/gameobject.h"

class GameObjectsHierarchyContainer
{
public:
    GameObjectsHierarchyContainer(GameObject& rootGameObject);

    void registerReportCallback(void (*callback)(GameObject&, void*), void* userData);
    void unregisterReportCallbck(void (*callback)(GameObject&, void*));
    void onUpdate();

private:
    GameObject& m_rootGameObject;
    std::map<void (*)(GameObject&, void*), void*> m_reportCallbacksWithUserData;
};

#endif // GAMEOBJECTSHIERARCHYCONTAINER_H
