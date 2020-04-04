#include <sstream>
#include "gameobjectcomponent.h"

GameObjectComponent::GameObjectComponent(const std::string& name) : m_name(name) {}

int GameObjectComponent::s_cloneNamePostfix = 0;

int GameObjectComponent::nextCloneNamePostfix()
{
    return GameObjectComponent::s_cloneNamePostfix++;
}
