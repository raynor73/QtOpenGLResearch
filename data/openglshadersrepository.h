#ifndef OPENGLSHADERSREPOSITORY_H
#define OPENGLSHADERSREPOSITORY_H

#include <map>
#include <string>
#include "data/openglerrordetector.h"
#include "data/shaderprograminfo.h"

class OpenGLShadersRepository
{
public:
    OpenGLShadersRepository(OpenGLErrorDetector& openGLErrorDetector);

    uint32_t findVertexShader(const std::string& name) const;
    uint32_t findFragmentShader(const std::string& name) const;
    ShaderProgramInfo findShaderProgram(const std::string& name) const;
    void createVertexShader(const std::string& name, const std::string& source);
    void createFragmentShader(const std::string& name, const std::string& source);
    void createShaderProgram(const std::string& name, uint32_t vertexShader, uint32_t fragmentShader);

private:
    OpenGLErrorDetector& m_openGLErrorDetector;

    std::map<std::string, uint32_t> m_vertexShaders;
    std::map<std::string, uint32_t> m_fragmentShaders;
    std::map<std::string, ShaderProgramInfo> m_shaderPrograms;
};

#endif // OPENGLSHADERSREPOSITORY_H
