#include "iboinfo.h"

IboInfo::IboInfo() : m_ibo(0), m_numberOfIndices(0) {}

IboInfo::IboInfo(uint32_t ibo, size_t numberOfIndices) : m_ibo(ibo), m_numberOfIndices(numberOfIndices) {}

uint32_t IboInfo::ibo() const
{
    return m_ibo;
}

size_t IboInfo::numberOfIndices() const
{
    return m_numberOfIndices;
}
