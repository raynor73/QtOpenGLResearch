#ifndef TEXTURESREPOSITORY_H
#define TEXTURESREPOSITORY_H

#include <string>
#include <vector>

class TexturesRepository
{
public:
    TexturesRepository();
    ~TexturesRepository() {};

    virtual void createTexture(const std::string& name, const std::string& path) = 0;
    virtual void createTexture(const std::string& name, int width, int height, const std::vector<uint8_t>& data) = 0;
    virtual void createTexture(const std::string& name, int width, int height) = 0;
    virtual void copyDataToTexture(const std::string& name, const std::vector<uint8_t>& data, bool generateMipmap) = 0;
    virtual void removeTexture(const std::string& name) = 0;
    virtual void removeAllTextures() = 0;
};

#endif // TEXTURESREPOSITORY_H
