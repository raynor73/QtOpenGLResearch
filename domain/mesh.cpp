#include "mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<uint16_t>& indices) :
    m_vertices(vertices), m_indices(indices)
{}

const std::vector<Vertex>& Mesh::vertices() const
{
    return m_vertices;
}

const std::vector<uint16_t>& Mesh::indices() const
{
    return m_indices;
}
