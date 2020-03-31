#ifndef VAOINFO_H
#define VAOINFO_H

#include <cstdint>
#include <cstddef>

class VaoInfo
{
public:
    VaoInfo();
    VaoInfo(uint32_t vao, size_t numberOfIndices);

    uint32_t vao() const { return m_vao; };
    size_t numberOfIndices() const { return m_numberOfIndices; };

private:
    uint32_t m_vao;
    size_t m_numberOfIndices;
};

#endif // VAOINFO_H
