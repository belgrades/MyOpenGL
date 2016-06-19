#ifndef QUAD_H
#define QUAD_H

#include <QDebug>
#include <QtOpenGL>

class quad : public figura
{
public:
    quad(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType);
    void dibujar_figura();
};


#endif // QUAD_H
