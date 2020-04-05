#include <sstream>
#include "gameobjectcomponent.h"

GameObjectComponent::GameObjectComponent(const std::string& name) : m_name(name) {}

std::shared_ptr<GameObjectComponent> GameObjectComponent::clone()
{
    std::stringstream cloneNameBuilder;
    cloneNameBuilder << m_name << nextCloneNamePostfix();
    return clone(cloneNameBuilder.str());
}

int GameObjectComponent::s_cloneNamePostfix = 0;

int GameObjectComponent::nextCloneNamePostfix()
{
    return GameObjectComponent::s_cloneNamePostfix++;
}
