#include "textureinfo.h"

TextureInfo::TextureInfo() :
    m_texture(0),
    m_width(0),
    m_height(0)
{}

TextureInfo::TextureInfo(GLuint texture, int width, int height) :
    m_texture(texture),
    m_width(width),
    m_height(height)
{}

TextureInfo& TextureInfo::operator=(const TextureInfo &other)
{
    if (&other == this) {
        return *this;
    }

    m_texture = other.m_texture;
    m_width = other.m_width;
    m_height = other.m_height;

    return *this;
}
