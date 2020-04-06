#include "researchscene.h"

#include "domain/mesh.h"
#include "domain/transformationcomponent.h"
#include "domain/materialcomponent.h"
#include "domain/meshcomponent.h"

ResearchScene::ResearchScene(GameObjectsHierarchyContainer& gameObjectsHierarchyContainer) :
    Scene(gameObjectsHierarchyContainer)
{
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0, 0)));
    vertices.push_back(Vertex(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1, 0)));
    vertices.push_back(Vertex(glm::vec3( 0.5,  0.5, 0.0), glm::vec2(1, 1)));
    vertices.push_back(Vertex(glm::vec3(-0.5,  0.5, 0.0), glm::vec2(0, 1)));

    std::vector<uint16_t> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(2);
    indices.push_back(3);
    indices.push_back(0);

    std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(vertices, indices);

    auto plane = std::make_shared<GameObject>("plane");
    auto transformComponent = std::make_shared<TransformationComponent>(
                "transform",
                glm::vec3(0),
                glm::identity<glm::quat>(),
                glm::vec3(1)
    );
    auto materialComponent = std::make_shared<MaterialComponent>(
                "plane",
                std::shared_ptr<std::string>(),
                glm::vec4(0, 0, 0.5, 1)
    );
    auto meshComponent = std::make_shared<MeshComponent>("mesh", "plane", mesh);
    plane->attachComponent(transformComponent);
    plane->attachComponent(materialComponent);
    plane->attachComponent(meshComponent);

    m_rootGameObject->attachChild(plane);
}
