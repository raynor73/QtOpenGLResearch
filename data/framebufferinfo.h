#ifndef FRAMEBUFFERINFO_H
#define FRAMEBUFFERINFO_H

#include <memory>
#include "data/assets/textureinfo.h"

class FrameBufferInfo
{
public:
    FrameBufferInfo();
    FrameBufferInfo(GLuint frameBuffer, std::shared_ptr<TextureInfo> textureInfo);

    GLuint frameBuffer() const { return m_frameBuffer; };
    std::shared_ptr<TextureInfo> textureInfo() { return m_textureInfo; };

    FrameBufferInfo& operator=(const FrameBufferInfo& other);

private:
    GLuint m_frameBuffer;
    std::shared_ptr<TextureInfo> m_textureInfo;
};

#endif // FRAMEBUFFERINFO_H
