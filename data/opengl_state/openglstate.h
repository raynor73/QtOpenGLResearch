#ifndef OPENGLSTATE_H
#define OPENGLSTATE_H

#include <QOpenGLFunctions_4_5_Core>

struct BlendFunction
{
    GLenum sFactor;
    GLenum dFactor;
};

struct Viewport
{
    GLint x;
    GLint y;
    GLsizei width;
    GLsizei height;
};

struct Scissor
{
    GLint x;
    GLint y;
    GLsizei width;
    GLsizei height;
};

struct OpenGLState
{
    Viewport viewport;
    Scissor scissor;
    bool blend;
    BlendFunction blendFunction;
    bool depthMask;
    GLenum depthFunction;
};

#endif // OPENGLSTATE_H
