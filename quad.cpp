#include "figura.h"
#include "quad.h"
#include <iostream>
using namespace std;

quad::quad(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType )
{
    puntos_control_opengl = opengl;
    puntos_control_pixel = pixel ;
    color = color1;
    done = false;
    initialize = true;
    my_type = myType;
}


void quad::dibujar_figura()
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

    if(puntos_control_opengl[0]->x()>=puntos_control_opengl[1]->x()){
        if(puntos_control_opengl[0]->y()>=puntos_control_opengl[1]->y()){ //III cuadrante
            puntos_control_opengl[2]->setX(puntos_control_opengl[1]->x());
            puntos_control_opengl[2]->setY(puntos_control_opengl[0]->y());
            puntos_control_opengl[3]->setX(puntos_control_opengl[0]->x());
            puntos_control_opengl[3]->setY(puntos_control_opengl[1]->y());
        }else{        //II cuadrante
            puntos_control_opengl[2]->setX(puntos_control_opengl[0]->x());
            puntos_control_opengl[2]->setY(puntos_control_opengl[1]->y());
            puntos_control_opengl[3]->setX(puntos_control_opengl[1]->x());
            puntos_control_opengl[3]->setY(puntos_control_opengl[0]->y());
        }
    }else{
        if(puntos_control_opengl[0]->y()>=puntos_control_opengl[1]->y()){  //IV cuadrante
            puntos_control_opengl[2]->setX(puntos_control_opengl[0]->x());
            puntos_control_opengl[2]->setY(puntos_control_opengl[1]->y());
            puntos_control_opengl[3]->setX(puntos_control_opengl[1]->x());
            puntos_control_opengl[3]->setY(puntos_control_opengl[0]->y());
        }else{         //I cuadrante
            puntos_control_opengl[2]->setX(puntos_control_opengl[1]->x());
            puntos_control_opengl[2]->setY(puntos_control_opengl[0]->y());
            puntos_control_opengl[3]->setX(puntos_control_opengl[0]->x());
            puntos_control_opengl[3]->setY(puntos_control_opengl[1]->y());
        }
    }

    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    glBegin(GL_QUADS);
        glVertex3f(puntos_control_opengl[0]->x(),puntos_control_opengl[0]->y(),0);
        glVertex3f(puntos_control_opengl[2]->x(),puntos_control_opengl[2]->y(),0);
        glVertex3f(puntos_control_opengl[1]->x(),puntos_control_opengl[1]->y(),0);
        glVertex3f(puntos_control_opengl[3]->x(),puntos_control_opengl[3]->y(),0);
    glEnd();
}
