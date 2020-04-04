#ifndef TEXTUREREPOSITORY2_H
#define TEXTUREREPOSITORY2_H

#include <cstdint>
#include <memory>
#include <vector>
#include <string>
#include "domain/assets/texturedata.h"
#include "domain/assets/texturearraydata.h"

class TextureRepository2
{
public:
    TextureRepository2() = delete;
    virtual ~TextureRepository2();

    virtual Texture loadTexture(const std::string& path) = 0;
    virtual TextureArray loadTextureArray(const std::vector<const std::string> paths) = 0;
};

#endif // TEXTUREREPOSITORY2_H
