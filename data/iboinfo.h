#ifndef IBOINFO_H
#define IBOINFO_H

#include <cstdint>
#include <cstddef>

class IboInfo
{
public:
    IboInfo();
    IboInfo(uint32_t ibo, size_t m_numberOfIndices);

    uint32_t ibo() const;
    size_t numberOfIndices() const;

private:
    uint32_t m_ibo;
    size_t m_numberOfIndices;
};

#endif // IBOINFO_H
