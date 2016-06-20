#include "figura.h"
#include "ellipse.h"
#include "math.h"
#include <iostream>
using namespace std;

ellipse::ellipse(QVector<QVector3D*> opengl, QVector<QVector3D*> pixel, QVector3D color1, figureType myType )
{
    puntos_control_opengl = opengl;
    puntos_control_pixel = pixel ;
    color = color1;
    done = false;
    initialize = true;
    my_type = myType;
}

void ellipse::PintarElipse(int x,int y,int minix, int miniy,int pint)
{
    glPointSize(2.0);
    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    glBegin(GL_POINTS);
        glVertex3f(PixelToOpenGLX(x+minix),PixelToOpenGLY(y+miniy),0.0f);
        glVertex3f(PixelToOpenGLX(x+minix),PixelToOpenGLY(-y+miniy),0.0f);
        glVertex3f(PixelToOpenGLX(-x+minix),PixelToOpenGLY(y+miniy),0.0f);
        glVertex3f(PixelToOpenGLX(-x+minix),PixelToOpenGLY(-y+miniy),0.0f);
    glEnd();
}

int ellipse::min(int x, int y){
    if (x < y)
        return x;
    return y;
}

void ellipse::dibujar_figura()
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


    glColor3f((GLfloat)color.x(), (GLfloat)color.y(), (GLfloat)color.z());
    vector <bool> A (16);

    int x0,x1,y0,y1,x,y,minix,miniy,pint;
    float a,b,d1,d2;
    x0=OpenGLToPixelX(puntos_control_opengl[0]->x());
    y0=OpenGLToPixelY(puntos_control_opengl[0]->y());
    x1=OpenGLToPixelX(puntos_control_opengl[1]->x());
    y1=OpenGLToPixelY(puntos_control_opengl[1]->y());
    minix=min(x0,x1);
    miniy=min(y0,y1);

    a=(float)abs(x0-x1)/2;
    b=(float)abs(y0-y1)/2;
    d1=(float)pow(b,2)+pow(a,2)*(-b+1/4);
    x=0;
    y=b;
    if(abs(y0-y1)<=1) {
        cout<<"GOLA"<<endl;
        glBegin(GL_LINES);
            glVertex3f(puntos_control_opengl[0]->x(), puntos_control_opengl[0]->y(), 0);
            glVertex3f(puntos_control_opengl[1]->x(), puntos_control_opengl[1]->y(), 0);
        glEnd();
    }else{
    pint=0;

    PintarElipse(x,y,a+minix,b+miniy,pint);
    while(pow(a,2)*(y-1/2)>pow(b,2)*(x+1)){
        if(d1<0){
            d1=d1+pow(b,2)*(2*x+3);
        }else{
            d1=d1+pow(b,2)*(2*x+3)+pow(a,2)*(-2*y+2);
            y=y-1;
        }
        x=x+1;
        pint++;
        pint=pint%16;
        PintarElipse(x,y,a+minix,b+miniy,pint);

    }
    d2=(float)pow(b,2)*pow((float)(x+1/2),2)+pow(a,2)*pow((float)y-1,2)-pow(a,2)*pow(b,2);
    while(y>0){
        if(d2<0){
            d2=d2+pow(b,2)*(2*x+2)+pow(a,2)*(-2*y+3);
            x=x+1;
        }else{
            d2=d2+pow(a,2)*(-2*y+3);
        }
        y=y-1;
        pint++;
        pint=pint%16;
        PintarElipse(x,y,a+minix,b+miniy,pint);
    }
    }
}
