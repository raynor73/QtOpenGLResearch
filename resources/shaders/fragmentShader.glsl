uniform sampler2D textureUniform;

varying vec2 uvVarying;

void main(void)
{
    gl_FragColor = texture2D(textureUniform, uvVarying);
}
