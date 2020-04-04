#ifndef TEXTUREARRAYDATA_H
#define TEXTUREARRAYDATA_H

#include <memory>
#include <vector>
#include <cstdint>

class TextureArray
{
public:
    TextureArray(int width, int height, int numberOfTextures, std::shared_ptr<const std::vector<uint8_t>> data);

    const int width;
    const int height;
    const int numberOfTextures;
    const std::shared_ptr<const std::vector<uint8_t>> data;
};

#endif // TEXTUREARRAYDATA_H
