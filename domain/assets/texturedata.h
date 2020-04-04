#ifndef TEXTUREDATA_H
#define TEXTUREDATA_H

#include <memory>
#include <vector>
#include <cstdint>

class Texture
{
public:
    Texture(int width, int height, std::shared_ptr<const std::vector<uint8_t>> data);

    const int width;
    const int height;
    const std::shared_ptr<const std::vector<uint8_t>> data;
};

#endif // TEXTUREDATA_H
