#version 410

uniform sampler2DArray textureUniform;
uniform int textureIndexUniform;

in vec2 uvVarying;

out vec4 FragColor;

void main(void)
{
    FragColor = texture(textureUniform, vec3(uvVarying, float(textureIndexUniform)));
}
