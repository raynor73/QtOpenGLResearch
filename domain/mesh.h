#ifndef MESH_H
#define MESH_H

#include <vector>
#include "domain/vertex.h"

class Mesh
{
public:
    Mesh();
    Mesh(const std::vector<Vertex>& vertices, const std::vector<uint16_t>& indices);

    const std::vector<Vertex>& vertices() const;
    const std::vector<uint16_t>& indices() const;

private:
    std::vector<Vertex> m_vertices;
    std::vector<uint16_t> m_indices;
};

#endif // MESH_H
