#ifndef FIGURA_H
#define FIGURA_H

#include <QtOpenGL>
#include "figure_type.h"

class figura
{
public:
    /*Vector de puntos para coordenadas OpenGL (-1,1)x(-1,1) y pixel (w, h) */
    QVector<QVector3D*> puntos_control_opengl, puntos_control_pixel;
    figureType my_type;
    QVector3D color;
    bool done;
    bool initialize;
    int stage;

public:
    int GL_WINDOW_WIDTH, GL_WINDOW_HEIGHT;
    GLfloat PixelToOpenGLX(int x);
    GLfloat PixelToOpenGLY(int y);
    GLint OpenGLToPixelX(float x);
    GLint OpenGLToPixelY(float y);
    virtual void dibujar_figura() = 0;
};

#endif // FIGURA_H
