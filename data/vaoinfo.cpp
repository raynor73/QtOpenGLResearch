#include "vaoinfo.h"

VaoInfo::VaoInfo() {}

VaoInfo::VaoInfo(uint32_t vao, size_t numberOfIndices) :
    m_vao(vao),
    m_numberOfIndices(numberOfIndices)
{}
