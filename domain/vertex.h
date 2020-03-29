#ifndef VERTEX_H
#define VERTEX_H

#include "domain/math/vector3f.h"

class Vertex
{
public:
    Vertex(const Vector3f& position);

    const Vector3f& position() const;
    void setPosition(const Vector3f& position);

    static const int VERTEX_COORDINATE_COMPONENTS = 3;
    static const int VERTEX_COMPONENTS = VERTEX_COORDINATE_COMPONENTS;

private:
    Vector3f m_position;
};

#endif // VERTEX_H
