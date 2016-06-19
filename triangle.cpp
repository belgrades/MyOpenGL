#include "figura.h"
#include "triangle.h"
#include <iostream>
using namespace std;

triangle::triangle(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType)
{
    puntos_control_opengl = opengl;
    puntos_control_pixel = pixel ;
    color = color1;
    done = false;
    initialize = true;
    stage = 0;
    my_type = myType;
}


void triangle::dibujar_figura()
{
    // Size of control points
    glPointSize(5.0);
    if(done)
        glColor3f(0.0,1.0,0.0);
    else
        glColor3f(1.0,1.0,0.0);


    // Drawing control points
    glBegin(GL_POINTS);
        for(int i=0;i<puntos_control_opengl.size();i++){
            glVertex3f(puntos_control_opengl[i]->x(),puntos_control_opengl[i]->y(),0);
        }
    glEnd();

    // Reference line
    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    glBegin(GL_LINES);
        glVertex3f(puntos_control_opengl[0]->x(), puntos_control_opengl[0]->y(), 0);
        glVertex3f(puntos_control_opengl[1]->x(), puntos_control_opengl[1]->y(), 0);
    glEnd();

    // Drawing figure
    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    glBegin(GL_TRIANGLES);
        glVertex3f(puntos_control_opengl[0]->x(), puntos_control_opengl[0]->y(), 0);
        glVertex3f(puntos_control_opengl[1]->x(), puntos_control_opengl[1]->y(), 0);
        glVertex3f(puntos_control_opengl[2]->x(), puntos_control_opengl[2]->y(), 0);
    glEnd();
}

