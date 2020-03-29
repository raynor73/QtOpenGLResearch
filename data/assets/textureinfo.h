#ifndef TEXTUREINFO_H
#define TEXTUREINFO_H

#include <cstdlib>

class TextureInfo
{
public:
    TextureInfo();
    TextureInfo(uint32_t texture, int width, int height);

    uint32_t texture() const { return m_texture; }
    int width() const { return m_width; }
    int height() const { return m_height; }

    TextureInfo& operator=(const TextureInfo& other);

private:
    uint32_t m_texture;
    int m_width;
    int m_height;
};

#endif // TEXTUREINFO_H
