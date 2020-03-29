#include <sstream>
#include <QOpenGLFunctions_4_5_Core>
#include "openglshadersrepository.h"
#include "domain/exception.h"

OpenGLShadersRepository::OpenGLShadersRepository(OpenGLErrorDetector& openGLErrorDetector) :
    m_openGLErrorDetector(openGLErrorDetector)
{}

uint32_t OpenGLShadersRepository::findVertexShader(const std::string& name) const
{
    if (m_vertexShaders.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Vertex shader " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_vertexShaders.at(name);
}

uint32_t OpenGLShadersRepository::findFragmentShader(const std::string& name) const
{
    if (m_fragmentShaders.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Fragment shader " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_fragmentShaders.at(name);
}

ShaderProgramInfo OpenGLShadersRepository::findShaderProgram(const std::string& name) const
{
    if (m_shaderPrograms.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Shader program " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_shaderPrograms.at(name);
}

void OpenGLShadersRepository::createVertexShader(const std::string& name, const std::string& source)
{
    if (m_vertexShaders.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Vertex shader " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t shader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* sourceChars = source.c_str();
    glShaderSource(shader, 1, &sourceChars, 0);
    glCompileShader(shader);

    m_vertexShaders[name] = shader;

    m_openGLErrorDetector.dispatchShaderCompilationError(shader, "OpenGLShadersRepository::createVertexShader");
}

void OpenGLShadersRepository::createFragmentShader(const std::string& name, const std::string& source)
{
    if (m_fragmentShaders.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Fragment shader " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t shader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* sourceChars = source.c_str();
    glShaderSource(shader, 1, &sourceChars, 0);
    glCompileShader(shader);

    m_fragmentShaders[name] = shader;

    m_openGLErrorDetector.dispatchShaderCompilationError(shader, "OpenGLShadersRepository::createFragmentShader");
}

void OpenGLShadersRepository::createShaderProgram(
        const std::string& name,
        uint32_t vertexShader,
        uint32_t fragmentShader
) {
    if (m_shaderPrograms.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Shader program " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    m_shaderPrograms[name] = ShaderProgramInfo(shaderProgram);

    m_openGLErrorDetector.dispatchShaderLinkingError(shaderProgram, "OpenGLShadersRepository::createShaderProgram");
    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLShadersRepository::createShaderProgram");
}
