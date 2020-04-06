#ifndef MESHRENDERERCOMPONENT_H
#define MESHRENDERERCOMPONENT_H

#include <QOpenGLFunctions_4_5_Core>
#include "domain/cameracomponent.h"
#include "data/framebufferinfo.h"
#include "data/lightsources.h"
#include "data/shaderprograminfo.h"

class MeshRendererComponent : public GameObjectComponent
{
public:
    MeshRendererComponent(const std::string& name);

    void render(const ShaderProgramInfo& shaderProgramInfo, CameraComponent& camera, const LightSources& lightSources);

    virtual const std::string& type() const override;
    virtual std::shared_ptr<GameObjectComponent> clone(const std::string& cloneName) override;

    static const std::string TYPE_NAME;
};

#endif // MESHRENDERERCOMPONENT_H
