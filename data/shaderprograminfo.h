#ifndef SHADERPROGRAMINFO_H
#define SHADERPROGRAMINFO_H

#include <cstdlib>

class ShaderProgramInfo
{
public:
    ShaderProgramInfo();
    ShaderProgramInfo(uint32_t shaderProgram);

    uint32_t shaderProgram() const;
    uint32_t positionAttribute() const;
    uint32_t uvAttribute() const;
    uint32_t textureUniform() const;
    uint32_t mvpMatrixUniform() const { return m_mvpMatrixUniform; };
    ShaderProgramInfo& operator=(const ShaderProgramInfo& other);

private:
    uint32_t m_shaderProgram;
    uint32_t m_positionAttribute;
    uint32_t m_uvAttribute;
    uint32_t m_textureUniform;
    uint32_t m_mvpMatrixUniform;
};

#endif // SHADERPROGRAMINFO_H
