#ifndef OPENGLTEXTURESREPOSITORY_H
#define OPENGLTEXTURESREPOSITORY_H

#include <string>
#include <map>
#include "data/openglerrordetector.h"
#include "data/assets/textureinfo.h"
#include "domain/assets/texturesrepository.h"

class OpenGLTexturesRepository : public TexturesRepository
{
public:
    OpenGLTexturesRepository(OpenGLErrorDetector& openGLErrorDetector);

    const TextureInfo& findTexture(const std::string& name) const;

    virtual void createTexture(const std::string& name, const std::string& path) override;
    virtual void createTexture(const std::string& name, int width, int height, const std::vector<uint8_t>& data) override;
    virtual void createTexture(const std::string& name, int width, int height) override;
    virtual void copyDataToTexture(const std::string& name, const std::vector<uint8_t>& data, bool generateMipmap) override;
    virtual void removeTexture(const std::string& name) override;
    virtual void removeAllTextures() override;

    void createTextureArray(const std::string& name, const std::vector<std::string>& paths);

private:
    OpenGLErrorDetector& m_openGLErrorDetector;
    std::map<std::string, TextureInfo> m_textures;
};

#endif // OPENGLTEXTURESREPOSITORY_H
