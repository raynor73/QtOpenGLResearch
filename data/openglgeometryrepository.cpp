#include <QOpenGLFunctions_4_5_Core>
#include <sstream>
#include "domain/exception.h"
#include "openglgeometryrepository.h"

OpenGLGeometryRepository::OpenGLGeometryRepository(OpenGLErrorDetector& openGLErrorDetector) :
    m_openGLErrorDetector(openGLErrorDetector)
{}

uint32_t OpenGLGeometryRepository::findVbo(const std::string& name) const
{
    if (m_vbos.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "VBO " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_vbos.at(name);
}

IboInfo OpenGLGeometryRepository::findIbo(const std::string& name) const
{
    if (m_ibos.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "IBO " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_ibos.at(name);
}

void OpenGLGeometryRepository::createStaticVertexBuffer(const std::string& name, const std::vector<float>& vertexData)
{
    if (m_vbos.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "VBO " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    m_vbos[name] = vbo;

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLGeometryRepository::createStaticVertexBuffer");
}

void OpenGLGeometryRepository::createStaticIndexBuffer(const std::string &name, const std::vector<uint16_t> &indices)
{
    if (m_ibos.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "IBO " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof (uint16_t), indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    m_ibos[name] = IboInfo(ibo, indices.size());

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLGeometryRepository::createStaticIndexBuffer");
}

void OpenGLGeometryRepository::removeStaticVertexBuffer(const std::string& name)
{
    if (m_vbos.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Static vertex buffer " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    uint32_t vbo = m_vbos[name];
    glDeleteBuffers(1, &vbo);

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLGeometryRepository::removeStaticVertexBuffer");
}

void OpenGLGeometryRepository::removeStaticIndexBuffer(const std::string& name)
{
    if (m_ibos.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Static index buffer " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    uint32_t ibo = m_ibos[name].ibo();
    glDeleteBuffers(1, &ibo);

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLGeometryRepository::removeStaticIndexBuffer");
}

void OpenGLGeometryRepository::removeAllBuffers()
{
    for (auto it = m_vbos.begin(); it != m_vbos.end(); ++it) {
        uint32_t vbo = it->second;
        glDeleteBuffers(1, &vbo);
    }
    m_vbos.clear();

    for (auto it = m_ibos.begin(); it != m_ibos.end(); ++it) {
        uint32_t ibo = it->second.ibo();
        glDeleteBuffers(1, &ibo);
    }
    m_ibos.clear();
}
