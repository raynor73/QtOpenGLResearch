#version 410

//attribute vec3 positionAttribute;
//attribute vec2 uvAttribute;
layout(location = 0) in vec3 positionAttribute;
layout(location = 1) in vec2 uvAttribute;

uniform mat4 mvpMatrixUniform;

//varying vec2 uvVarying;
out vec2 uvVarying;

void main(void)
{
    uvVarying = uvAttribute;
    gl_Position = mvpMatrixUniform * vec4(positionAttribute, 1.0);
}
