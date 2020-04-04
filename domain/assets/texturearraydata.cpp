#include "texturearraydata.h"

TextureArray::TextureArray(int width, int height, int numberOfTextures, std::shared_ptr<const std::vector<uint8_t>> data) :
    width(width),
    height(height),
    numberOfTextures(numberOfTextures),
    data(data)
{}
