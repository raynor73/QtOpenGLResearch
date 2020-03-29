#include <QOpenGLFunctions_4_5_Core>
#include <QImage>
#include <sstream>
#include "domain/exception.h"
#include "opengltexturesrepository.h"

OpenGLTexturesRepository::OpenGLTexturesRepository(OpenGLErrorDetector& openGLErrorDetector) :
    m_openGLErrorDetector(openGLErrorDetector)
{}

const TextureInfo& OpenGLTexturesRepository::findTexture(const std::string& name) const
{
    if (m_textures.count(name) == 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Texture " << name << " not found";
        throw Exception(messageBuilder.str());
    }

    return m_textures.at(name);
}

void OpenGLTexturesRepository::createTexture(const std::string& name, const std::string& path)
{
    if (m_textures.count(name) > 0) {
        std::stringstream messageBuilder;
        messageBuilder << "Texture " << name << " already exists";
        throw Exception(messageBuilder.str());
    }

    uint32_t texture;
    glGenTextures(1, &texture);

    QImage image(QString::fromStdString(path));
    if (image.isNull()) {
        std::stringstream messageBuilder;
        messageBuilder << "Error loading texturev " << name;
        throw Exception(messageBuilder.str());
    }

    /*val bitmapStream = context.assets.open(path)
    val originalBitmap = BitmapFactory.decodeStream(bitmapStream)
    val flipVerticallyMatrix = Matrix()
    flipVerticallyMatrix.postScale(1f, -1f, originalBitmap.width / 2f, originalBitmap.height / 2f)
    val bitmap = Bitmap.createBitmap(
        originalBitmap,
        0,
        0,
        originalBitmap.width,
        originalBitmap.height,
        flipVerticallyMatrix,
        true
    )
    originalBitmap.recycle()
    bitmapStream.close()*/

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width(), image.height(), 0, GL_RGBA, GL_BYTE, image.bits());
    //GLUtils.texImage2D(GLES20.GL_TEXTURE_2D, 0, bitmap, 0)

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    m_textures[name] = TextureInfo(texture, image.width(), image.height());

    m_openGLErrorDetector.dispatchOpenGLErrors("OpenGLTexturesRepository::createTexture(const std::string& name, const std::string& path)");
}

void OpenGLTexturesRepository::createTexture(
        const std::string& name,
        int width, int height,
        const std::vector<uint8_t>& data
) {

}

void OpenGLTexturesRepository::createTexture(const std::string& name, int width, int height)
{

}

void OpenGLTexturesRepository::copyDataToTexture(
        const std::string& name,
        const std::vector<uint8_t>& data,
        bool generateMipmap
) {

}

void OpenGLTexturesRepository::removeTexture(const std::string& name)
{

}

void OpenGLTexturesRepository::removeAllTextures()
{

}
