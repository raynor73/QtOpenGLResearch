#include <QOpenGLFunctions_4_5_Core>
#include <iostream>
#include <sstream>
#include "openglerrordetector.h"

OpenGLErrorDetector::OpenGLErrorDetector() {
    m_openGLErrorMap[GL_INVALID_ENUM] = "GL_INVALID_ENUM";
    m_openGLErrorMap[GL_INVALID_VALUE] = "GL_INVALID_VALUE";
    m_openGLErrorMap[GL_INVALID_OPERATION] = "GL_INVALID_OPERATION";
    m_openGLErrorMap[GL_STACK_OVERFLOW] = "GL_STACK_OVERFLOW";
    m_openGLErrorMap[GL_STACK_UNDERFLOW] = "GL_STACK_UNDERFLOW";
    m_openGLErrorMap[GL_OUT_OF_MEMORY] = "GL_OUT_OF_MEMORY";
    m_openGLErrorMap[GL_INVALID_FRAMEBUFFER_OPERATION] = "GL_INVALID_FRAMEBUFFER_OPERATION";

    m_framebufferStatusMap[GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT] = "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
    m_framebufferStatusMap[GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT] =
            "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
    m_framebufferStatusMap[GL_FRAMEBUFFER_UNSUPPORTED] = "GL_FRAMEBUFFER_UNSUPPORTED";
}

void OpenGLErrorDetector::dispatchOpenGLErrors(const std::string& locationName)
{
    auto error = glGetError();
    while (error != GL_NO_ERROR) {
        m_isOpenGLErrorDetected = true;
        std::stringstream errorDescriptionBuilder;
        if (m_openGLErrorMap.count(error) > 0) {
            errorDescriptionBuilder << m_openGLErrorMap[error];
        } else {
            errorDescriptionBuilder << "Unknown OpenGL error: " << error << "\n";
        }
        std::cerr
                << "OpenGL error detected at "
                << locationName
                << " "
                << errorDescriptionBuilder.str()
                << "\n";
        error = glGetError();
    }
}

void OpenGLErrorDetector::dispatchShaderCompilationError(int shader, const std::string &locationName)
{
    int result;
    char infoLogBuffer[1024];
    int infoLogLength;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        m_isOpenGLErrorDetected = true;
        glGetShaderInfoLog(shader, sizeof (infoLogBuffer), &infoLogLength, infoLogBuffer);
        std::cerr
                << "OpenGL shader compilation failure detected at "
                << locationName
                << " "
                << infoLogBuffer
                << "\n";
    }
}

void OpenGLErrorDetector::dispatchShaderLinkingError(int shader, const std::string &locationName)
{
    int result;
    glGetProgramiv(shader, GL_LINK_STATUS, &result);
    if (result == GL_FALSE) {
        m_isOpenGLErrorDetected = true;
        std::cerr
                << "OpenGL shader linking failure detected at "
                << locationName
                << "\n";
    }
}

void OpenGLErrorDetector::checkFramebufferStatus(const std::string& locationName)
{
    auto framebufferStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (framebufferStatus != GL_FRAMEBUFFER_COMPLETE) {
        m_isOpenGLErrorDetected = true;
        std::stringstream statusDescriptionBuilder;
        if (m_framebufferStatusMap.count(framebufferStatus) > 0) {
            statusDescriptionBuilder << m_framebufferStatusMap[framebufferStatus];
        } else {
            statusDescriptionBuilder << "Unknown OpenGL framebuffer status: " << framebufferStatus << "\n";
        }
        std::cerr
                << "Incomplete framebuffer status at "
                << locationName
                << " "
                << statusDescriptionBuilder.str()
                << "\n";
    }
}
