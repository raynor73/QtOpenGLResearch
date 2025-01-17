#ifndef OPENGLGEOMETRYREPOSITORY_H
#define OPENGLGEOMETRYREPOSITORY_H

#include <map>
#include <string>
#include "data/iboinfo.h"
#include "data/vaoinfo.h"
#include "data/openglerrordetector.h"
#include "domain/geometryrepository.h"

class OpenGLGeometryRepository : public GeometryRepository
{
public:
    OpenGLGeometryRepository(OpenGLErrorDetector& openGLErrorDetector);

    uint32_t findVbo(const std::string& name) const;
    IboInfo findIbo(const std::string& name) const;
    const VaoInfo& findVao(const std::string& name) const;

    virtual void storeMeshData(const std::string& name, const Mesh& mesh) override;
    virtual void removeMeshData(const std::string& name) override;

    virtual void createStaticVertexBuffer(const std::string& name, const std::vector<float>& vertexData) override;
    virtual void createStaticIndexBuffer(const std::string& name, const std::vector<uint16_t>& indices) override;
    virtual void removeStaticVertexBuffer(const std::string& name) override;
    virtual void removeStaticIndexBuffer(const std::string& name) override;
    virtual void removeAllBuffers() override;

private:
    OpenGLErrorDetector& m_openGLErrorDetector;

    std::map<std::string, uint32_t> m_vbos;
    std::map<std::string, IboInfo> m_ibos;
    std::map<std::string, VaoInfo> m_vaos;
};

#endif // OPENGLGEOMETRYREPOSITORY_H
