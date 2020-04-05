#ifndef TEXTUREINFO_H
#define TEXTUREINFO_H

#include <cstdlib>
#include <QOpenGLFunctions_4_5_Core>

class TextureInfo
{
public:
    TextureInfo();
    TextureInfo(GLuint texture, int width, int height);

    GLuint texture() const { return m_texture; }
    int width() const { return m_width; }
    int height() const { return m_height; }

    TextureInfo& operator=(const TextureInfo& other);

private:
    GLuint m_texture;
    int m_width;
    int m_height;
};

#endif // TEXTUREINFO_H
