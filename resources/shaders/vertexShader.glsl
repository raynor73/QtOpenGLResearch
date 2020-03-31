#version 410

layout(location = 0) in vec3 positionAttribute;
layout(location = 1) in vec2 uvAttribute;

uniform mat4 mvpMatrixUniform;

out vec2 uvVarying;

void main(void)
{
    uvVarying = uvAttribute;
    gl_Position = mvpMatrixUniform * vec4(positionAttribute, 1.0);
}
