#include "texturedata.h"

Texture::Texture(int width, int height, std::shared_ptr<const std::vector<uint8_t>> data) :
    width(width),
    height(height),
    data(data)
{}
