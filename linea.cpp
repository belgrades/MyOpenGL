#include "figura.h"
#include "linea.h"
#include <iostream>
using namespace std;

linea::linea(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1)
{
    puntos_control_opengl = opengl;
    puntos_control_pixel = pixel ;
    color = color1;
    qDebug()<<"Linea aaaa "<<color.z();
}


void linea::dibujar_figura()
{
    qDebug()<<"Linea dfsdfsdfsdf "<<color.x();
    cout<<"Linea dfsdfsdfsdf "<<color.x();
    glPointSize(5.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POINTS);
        for(int i=0;i<puntos_control_opengl.size();i++){
            glVertex3f(puntos_control_opengl.at(i)->x(),puntos_control_opengl.at(i)->y(),0);
        }
    glEnd();

    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    glBegin(GL_LINES);
        glVertex3f(puntos_control_opengl.at(0)->x(), puntos_control_opengl.at(0)->y(), 0);
        glVertex3f(puntos_control_opengl.at(1)->x(), puntos_control_opengl.at(1)->y(), 0);
    glEnd();
}
