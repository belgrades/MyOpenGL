#ifndef ELLIPSE_H
#define ELLIPSE_H


#include <QDebug>
#include <QtOpenGL>


class ellipse : public figura
{
public:
    ellipse(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType);
    void PintarElipse(int x,int y,int minix, int miniy, int pint);
    int min(int x, int y);
    void dibujar_figura();
};


#endif // ELLIPSE_H
