#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QDebug>
#include <QtOpenGL>


class triangle : public figura
{
public:
    triangle(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType);
    void dibujar_figura();
};

#endif // TRIANGLE_H
