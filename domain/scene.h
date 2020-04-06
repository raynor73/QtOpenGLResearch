#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include "domain/game_object/gameobject.h"
#include "domain/gameobjectshierarchycontainer.h"

class Scene
{
public:
    Scene(GameObjectsHierarchyContainer& gameObjectsHierarchyContainer);
    virtual ~Scene();

    virtual void onUpdate();

private:
    GameObjectsHierarchyContainer& m_gameObjectsHierarchyContainer;
    std::shared_ptr<GameObject> m_rootGameObject;
};

#endif // SCENE_H
