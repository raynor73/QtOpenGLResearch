#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <string>
#include <memory>
#include "domain/mesh.h"
#include "domain/assets/texturedata.h"
#include "domain/assets/texturearraydata.h"
#include "domain/assets/texturerepository2.h"

class RenderingEngine
{
public:
    RenderingEngine() = delete;
    virtual ~RenderingEngine();

    virtual void addMesh(const std::string& name, const Mesh& mesh) = 0;
    virtual void removeMesh(const std::string& name) = 0;
    virtual void addTexture(const std::string& name, const Texture& texture) = 0;
    virtual void removeTexture(const std::string& name) = 0;
    virtual void addTextureArray(const std::string& name, const TextureArray& textureArray) = 0;
};

#endif // RENDERINGENGINE_H