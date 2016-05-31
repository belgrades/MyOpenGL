#ifndef LINEA_H
#define LINEA_H

#include <QDebug>
#include <QtOpenGL>


class linea : public figura
{
public:
    linea(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1);
    void dibujar_figura();
};

#endif // LINEA_H
