#include <sstream>
#include "gameobject.h"
#include "domain/exception.h"

int GameObject::s_cloneNamePostfix = 0;

int GameObject::nextCloneNamePostfix()
{
    return GameObject::s_cloneNamePostfix++;
}

GameObject::GameObject(const std::string& name) : m_name(name) {}

void GameObject::attachChild(std::shared_ptr<GameObject> child)
{
    if (m_children.count(child->name()) > 0) {
        std::stringstream msgBuilder;
        msgBuilder << "Game object '" << m_name << "' already has child named '" << child->name() << "'";
        throw Exception(msgBuilder.str());
    }

    m_children[child->name()] = child;
    child->setParent(std::make_shared<GameObject>(*this));
}

void GameObject::detachChild(std::shared_ptr<GameObject> child)
{
    if (m_children.count(child->name()) == 0) {
        std::stringstream msgBuilder;
        msgBuilder << "Game object '" << m_name << "' doesn't have child named '" << child->name() << "'";
        throw Exception(msgBuilder.str());
    }

    m_children.erase(child->name());
    child->setParent(std::shared_ptr<GameObject>());
}

void GameObject::attachComponent(std::shared_ptr<GameObjectComponent> component)
{
    std::map<std::string, std::shared_ptr<GameObjectComponent>>& components = m_componentsByType[component->type()];

    if (components.count(component->name()) > 0) {
        std::stringstream msgBuilder;
        msgBuilder << "Game object '" << m_name << "' already has component named '" << component->name() << "'";
        throw Exception(msgBuilder.str());
    }

    components[component->name()] = component;
    //component->setGameObject(std::make_shared<GameObject>(*this));
}

void GameObject::detachComponent(std::shared_ptr<GameObjectComponent> component)
{
    std::map<std::string, std::shared_ptr<GameObjectComponent>>& components = m_componentsByType[component->type()];

    if (components.count(component->name()) == 0) {
        std::stringstream msgBuilder;
        msgBuilder << "Game object '" << m_name << "' doesn't have component named '" << component->name() << "'";
        throw Exception(msgBuilder.str());
    }

    components.erase(component->name());
    //component->setGameObject(std::make_shared<GameObject>());
}

void GameObject::onStart()
{
    for (auto components = m_componentsByType.begin(); components != m_componentsByType.end(); ++components) {
        for (auto it = components->second.begin(); it != components->second.end(); ++it) {
            it->second->onStart();
        }
    }

    for (auto it = m_children.begin(); it != children().end(); ++it) {
        it->second->onStart();
    }
}

void GameObject::onUpdate()
{
    if (m_isEnabled) {
        for (auto components = m_componentsByType.begin(); components != m_componentsByType.end(); ++components) {
            for (auto it = components->second.begin(); it != components->second.end(); ++it) {
                it->second->onUpdate();
            }
        }

        for (auto it = m_children.begin(); it != children().end(); ++it) {
            it->second->onUpdate();
        }
    }
}

std::shared_ptr<GameObject> GameObject::clone()
{
    std::stringstream cloneNameBuilder;
    cloneNameBuilder << m_name << nextCloneNamePostfix();

    return clone(cloneNameBuilder.str());
}

std::shared_ptr<GameObject> GameObject::clone(const std::string& cloneName)
{
    GameObject *clonedObject = new GameObject(cloneName);

    for (auto components = m_componentsByType.begin(); components != m_componentsByType.end(); ++components) {
        for (auto it = components->second.begin(); it != components->second.end(); ++it) {
            clonedObject->attachComponent(it->second->clone());
        }
    }

    for (auto it = m_children.begin(); it != children().end(); ++it) {
        clonedObject->attachChild(it->second->clone());
    }

    return std::shared_ptr<GameObject>(clonedObject);
}

std::shared_ptr<GameObjectComponent> GameObject::findComponent(const std::string& type)
{
    if (m_componentsByType.count(type) > 0) {
        return m_componentsByType[type].begin()->second;
    } else {
        return std::shared_ptr<GameObjectComponent>();
    }
}

std::map<std::string, std::shared_ptr<GameObjectComponent>> GameObject::findComponents(const std::string& type)
{
    if (m_componentsByType.count(type) > 0) {
        return m_componentsByType[type];
    } else {
        return std::map<std::string, std::shared_ptr<GameObjectComponent>>();
    }
}
