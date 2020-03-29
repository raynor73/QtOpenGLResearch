#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "domain/mesh.h"

std::vector<float> extractVerticesData(const Mesh& mesh);
//std::vector<uint16_t> extractIndicesData(const Mesh& mesh);
std::string loadTextFromResources(const std::string& path);

#endif // UTILS_H
