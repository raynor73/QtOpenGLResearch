#ifndef MESHCONTROLLER_H
#define MESHCONTROLLER_H

class MeshController
{
public:
    MeshController();
    virtual ~MeshController() {};

    virtual float xRotationFactor() const = 0;
    virtual float yRotationFactor() const = 0;
    virtual float zRotationFactor() const = 0;
    virtual float movementFactor() const = 0;
};

#endif // MESHCONTROLLER_H
