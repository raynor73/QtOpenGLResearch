#ifndef SCENE_H
#define SCENE_H

#include "domain/game_object/gameobject.h"

class Scene
{
public:
    Scene();
    virtual ~Scene() {};

    virtual void onUpdate();

private:
    GameObject m_rootGameObject;
};

#endif // SCENE_H
