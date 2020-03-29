#include "vertex.h"

Vertex::Vertex(const Vector3f& position) : m_position(position) {}

const Vector3f& Vertex::position() const
{
    return m_position;
}

void Vertex::setPosition(const Vector3f &position)
{
    m_position = position;
}
