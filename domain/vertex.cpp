#include "vertex.h"

Vertex::Vertex(const Vector3f& position, const Vector2f& uv) :
    m_position(position),
    m_uv(uv)
{}

const Vector3f& Vertex::position() const
{
    return m_position;
}

void Vertex::setPosition(const Vector3f &position)
{
    m_position = position;
}

const Vector2f& Vertex::uv() const
{
    return m_uv;
}

void Vertex::setUv(const Vector2f &uv)
{
    m_uv = uv;
}
