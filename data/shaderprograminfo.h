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
    ShaderProgramInfo& operator=(const ShaderProgramInfo& other);

private:
    uint32_t m_shaderProgram;
    uint32_t m_positionAttribute;
};

#endif // SHADERPROGRAMINFO_H
