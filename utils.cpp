#include <QString>
#include <QFile>
#include <sstream>
#include "domain/exception.h"
#include "utils.h"

std::vector<float> extractVerticesData(const Mesh& mesh)
{
    std::vector<float> verticesData;
    const std::vector<Vertex>& vertices = mesh.vertices();
    for (auto it = vertices.begin(); it != vertices.end(); ++it) {
        verticesData.push_back(it->position().x);
        verticesData.push_back(it->position().y);
        verticesData.push_back(it->position().z);

        verticesData.push_back(it->uv().x);
        verticesData.push_back(it->uv().y);
    }
    return verticesData;
}

std::string loadTextFromResources(const std::string& path)
{
    QString data;
    QString fileName = QString::fromStdString(path);

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        std::stringstream messageBuilder;
        messageBuilder << "Error opening resource file " << path;
        throw Exception(messageBuilder.str());
    }

    data = file.readAll();

    file.close();

    return data.toStdString();
}
