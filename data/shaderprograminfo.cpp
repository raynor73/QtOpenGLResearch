#include <QOpenGLFunctions_4_5_Core>
#include "shaderprograminfo.h"

ShaderProgramInfo::ShaderProgramInfo() {}

ShaderProgramInfo::ShaderProgramInfo(uint32_t shaderProgram) :
    m_shaderProgram(shaderProgram),
    m_positionAttribute(glGetAttribLocation(m_shaderProgram, "positionAttribute")),
    m_uvAttribute(glGetAttribLocation(m_shaderProgram, "uvAttribute")),
    m_textureUniform(glGetUniformLocation(m_shaderProgram, "textureUniform")),
    m_mvpMatrixUniform(glGetUniformLocation(m_shaderProgram, "mvpMatrixUniform"))
{}

ShaderProgramInfo& ShaderProgramInfo::operator=(const ShaderProgramInfo& other)
{
    if (&other == this) {
        return *this;
    }

    m_shaderProgram = other.m_shaderProgram;
    m_positionAttribute = other.m_positionAttribute;
    m_uvAttribute = other.m_uvAttribute;
    m_textureUniform = other.m_textureUniform;
    m_mvpMatrixUniform = other.m_mvpMatrixUniform;

    return *this;
}

uint32_t ShaderProgramInfo::shaderProgram() const
{
    return m_shaderProgram;
}

uint32_t ShaderProgramInfo::positionAttribute() const
{
    return m_positionAttribute;
}

uint32_t ShaderProgramInfo::uvAttribute() const
{
    return m_uvAttribute;
}

uint32_t ShaderProgramInfo::textureUniform() const
{
    return m_textureUniform;
}
