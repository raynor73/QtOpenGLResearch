attribute vec4 positionAttribute;
attribute vec2 uvAttribute;

varying vec2 uvVarying;

void main(void)
{
    uvVarying = uvAttribute;
    gl_Position = positionAttribute;
}
