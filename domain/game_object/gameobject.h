#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <vector>
#include <map>
#include <string>
#include "domain/game_object/gameobjectcomponent.h"

class GameObject
{
public:
    explicit GameObject(const std::string& name);

    const std::string& name() const { return m_name; };

    std::shared_ptr<GameObject> parent() { return m_parent.lock(); };
    void setParent(std::shared_ptr<GameObject> parent) { m_parent = parent; };
    std::map<std::string, std::shared_ptr<GameObject>>& children() { return m_children; };

    void attachChild(std::shared_ptr<GameObject> child);
    void detachChild(std::shared_ptr<GameObject> child);

    void attachComponent(std::shared_ptr<GameObjectComponent> component);
    void detachComponent(std::shared_ptr<GameObjectComponent> component);

    void onStart();
    void onUpdate();

    std::shared_ptr<GameObject> clone();
    std::shared_ptr<GameObject> clone(const std::string& cloneName);

    std::shared_ptr<GameObjectComponent> findComponent(const std::string& type);
    std::map<std::string, std::shared_ptr<GameObjectComponent>> findComponents(const std::string& type);

private:
    bool m_isEnabled = true;
    std::string m_name;
    std::weak_ptr<GameObject> m_parent;
    std::map<std::string, std::shared_ptr<GameObject>> m_children;
    std::map<std::string, std::map<std::string, std::shared_ptr<GameObjectComponent>>> m_componentsByType;

    static int s_cloneNamePostfix;

    static int nextCloneNamePostfix();
};

#endif // GAMEOBJECT_H
