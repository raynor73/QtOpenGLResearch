#ifndef OPENGLERRORDETECTOR_H
#define OPENGLERRORDETECTOR_H

#include <string>
#include <map>

class OpenGLErrorDetector
{
public:
    OpenGLErrorDetector();

    bool isOpenGLErrorDetected() const { return m_isOpenGLErrorDetected; }
    void dispatchOpenGLErrors(const std::string& locationName);
    void dispatchShaderCompilationError(int shader, const std::string& locationName);
    void dispatchShaderLinkingError(int shader, const std::string& locationName);
    void checkFramebufferStatus(const std::string& locationName);

private:
    std::map<int, std::string> m_openGLErrorMap;
    std::map<int, std::string> m_framebufferStatusMap;
    bool m_isOpenGLErrorDetected = false;
};

#endif // OPENGLERRORDETECTOR_H
