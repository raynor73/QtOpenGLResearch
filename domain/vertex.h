#ifndef VERTEX_H
#define VERTEX_H

#include "domain/math/vector3f.h"
#include "domain/math/vector2f.h"

class Vertex
{
public:
    Vertex(const Vector3f& position, const Vector2f& uv);

    const Vector3f& position() const;
    void setPosition(const Vector3f& position);
    const Vector2f& uv() const;
    void setUv(const Vector2f& uv);

    static const int VERTEX_COORDINATE_COMPONENTS = 3;
    static const int VERTEX_UV_COMPONENTS = 2;
    static const int VERTEX_COMPONENTS = VERTEX_COORDINATE_COMPONENTS + VERTEX_UV_COMPONENTS;

private:
    Vector3f m_position;
    Vector2f m_uv;
};

#endif // VERTEX_H
