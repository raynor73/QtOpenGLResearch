#ifndef VERTEX_H
#define VERTEX_H

#include "glm/glm.hpp"

class Vertex
{
public:
    Vertex(const glm::vec3& position, const glm::vec2& uv);

    const glm::vec3& position() const { return m_position; }
    void setPosition(const glm::vec3& position) { m_position = position; }
    const glm::vec2& uv() const { return m_uv; }
    void setUv(const glm::vec2& uv) { m_uv = uv; }

    static const int VERTEX_COORDINATE_COMPONENTS = 3;
    static const int VERTEX_UV_COMPONENTS = 2;
    static const int VERTEX_COMPONENTS = VERTEX_COORDINATE_COMPONENTS + VERTEX_UV_COMPONENTS;

private:
    glm::vec3 m_position;
    glm::vec2 m_uv;
};

#endif // VERTEX_H
