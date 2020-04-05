#ifndef LIGHTSOURCES_H
#define LIGHTSOURCES_H

#include <vector>
#include <memory>
#include "glm/glm.hpp"
#include "domain/light_sources/directionallight.h"

class LightSources
{
public:
    LightSources();

    const glm::vec3& ambient() const { return m_ambient; };
    void setAmbient(const glm::vec3 ambient) { m_ambient = ambient; };
    const std::vector<std::shared_ptr<DirectionalLight>>& directionalLights() const { return m_directionalLights; };
    void addDirectionalLight(std::shared_ptr<DirectionalLight> directionalLight);
    void clear();

private:
    glm::vec3 m_ambient;
    std::vector<std::shared_ptr<DirectionalLight>> m_directionalLights;
};

#endif // LIGHTSOURCES_H
