#ifndef GAMEOBJECTCOMPONENT_H
#define GAMEOBJECTCOMPONENT_H

#include <memory>
#include <string>

class GameObject;

class GameObjectComponent
{
public:
    explicit GameObjectComponent(const std::string& name);
    virtual ~GameObjectComponent() {};

    virtual const std::string& type() const = 0;
    const std::string& name() const { return m_name; };

    std::shared_ptr<GameObject> gameObject() { return m_gameObject.lock(); };
    void setGameObject(std::shared_ptr<GameObject> gameObject) { m_gameObject = gameObject; };

    virtual void onStart() {};
    virtual void onUpdate() {};
    virtual void onAttach() {};
    virtual void onDetach() {};

    std::shared_ptr<GameObjectComponent> clone();
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) = 0;

protected:
    bool m_isEnabled = true;
    std::string m_name;
    std::weak_ptr<GameObject> m_gameObject;

    static int nextCloneNamePostfix();

private:
    static int s_cloneNamePostfix;
};

#endif // GAMEOBJECTCOMPONENT_H
