#include <QOpenGLFunctions_4_5_Core>
#include "shaderprograminfo.h"

ShaderProgramInfo::ShaderProgramInfo() {}

ShaderProgramInfo::ShaderProgramInfo(uint32_t shaderProgram) :
    m_shaderProgram(shaderProgram),
    m_positionAttribute(glGetAttribLocation(m_shaderProgram, "position"))
{}

ShaderProgramInfo& ShaderProgramInfo::operator=(const ShaderProgramInfo& other)
{
    if (&other == this) {
        return *this;
    }

    m_shaderProgram = other.m_shaderProgram;
    m_positionAttribute = other.m_positionAttribute;

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
