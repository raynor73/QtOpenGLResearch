#include "framebufferinfo.h"

FrameBufferInfo::FrameBufferInfo() :
    m_frameBuffer(0),
    m_textureInfo(std::shared_ptr<TextureInfo>())
{}

FrameBufferInfo::FrameBufferInfo(GLuint frameBuffer, std::shared_ptr<TextureInfo> textureInfo) :
    m_frameBuffer(frameBuffer),
    m_textureInfo(textureInfo)
{}

FrameBufferInfo& FrameBufferInfo::operator=(const FrameBufferInfo& other)
{
    if (&other == this) {
        return *this;
    }

    m_frameBuffer = other.m_frameBuffer;
    m_textureInfo = other.m_textureInfo;

    return *this;
}
