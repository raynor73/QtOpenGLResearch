#ifndef GEOMETRYREPOSITORY_H
#define GEOMETRYREPOSITORY_H

#include <string>
#include <vector>

class GeometryRepository
{
public:
    GeometryRepository();
    virtual ~GeometryRepository() {};

    virtual void createStaticVertexBuffer(const std::string& name, const std::vector<float>& vertexData) = 0;
    virtual void createStaticIndexBuffer(const std::string& name, const std::vector<uint16_t>& indices) = 0;
    virtual void removeStaticVertexBuffer(const std::string& name) = 0;
    virtual void removeStaticIndexBuffer(const std::string& name) = 0;
    virtual void removeAllBuffers() = 0;
};

#endif // GEOMETRYREPOSITORY_H