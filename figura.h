#ifndef FIGURA_H
#define FIGURA_H

#include <QtOpenGL>

class figura
{
public:
    /*Vector de puntos para coordenadas OpenGL (-1,1)x(-1,1) y pixel (w, h) */
    QVector<QVector3D*> puntos_control_opengl, puntos_control_pixel;
    QVector3D color;
    bool done;
    bool initialize;

public:
    virtual void dibujar_figura() = 0;
};

#endif // FIGURA_H
