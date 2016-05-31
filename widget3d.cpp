#include <QtWidgets>
#include <QtOpenGL>
#include "widget3d.h"

widget3d::widget3d(QWidget *parent) :
    QGLWidget(parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
}


void widget3d::initializeGL(){
    qglClearColor(Qt::black);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    paintGL();

}
void widget3d::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

    qglColor(Qt::red);
      glBegin(GL_QUADS);
          glNormal3f(0,0,-1);
          glVertex3f(-1,-1,0);
          glVertex3f(-1,1,0);
          glVertex3f(1,1,0);
          glVertex3f(1,-1,0);

      glEnd();
      glBegin(GL_TRIANGLES);
          glNormal3f(0,-1,(GLfloat)0.707);
          glVertex3f(-1,-1,0);
          glVertex3f(1,-1,0);
          glVertex3f(0,0,(GLfloat)1.2);
      glEnd();
      glBegin(GL_TRIANGLES);
          glNormal3f(1,0, (GLfloat)0.707);
          glVertex3f(1,-1,0);
          glVertex3f(1,1,0);
          glVertex3f(0,0,(GLfloat)1.2);
      glEnd();
      glBegin(GL_TRIANGLES);
          glNormal3f(0,1,(GLfloat)0.707);
          glVertex3f(1,1,0);
          glVertex3f(-1,1,0);
          glVertex3f(0,0,(GLfloat)1.2);
      glEnd();
      glBegin(GL_TRIANGLES);
          glNormal3f(-1,0,(GLfloat)0.707);
          glVertex3f(-1,1,0);
          glVertex3f(-1,-1,0);
          glVertex3f(0,0,(GLfloat)1.2);
      glEnd();

}
void widget3d::resizeGL(int width, int height){
    cout<<"resizeGL>> w "<<width<<" h "<<height<<endl;

    GL_WINDOW_WIDTH = width;
    GL_WINDOW_HEIGHT = height;

    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    //glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 0.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 0.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);

}

QSize widget3d::minimumSizeHint() const{
    return QSize(50, 50);
}

QSize widget3d::sizeHint() const{
    return QSize(600, 600);
}

void widget3d::mousePressEvent(QMouseEvent *event){

    lastPos = event->pos();
    cout<<"mousePressEvent>> "<<event->x()<<" "<<endl;
    cout<<"mousePressEvent>> "<<event->y()<<" "<<endl;
}

void widget3d::mouseMoveEvent(QMouseEvent *event){

    cout<<"mouseMoveEvent>> "<<event->x()<<endl;
    cout<<"mouseMoveEvent>> "<<event->y()<<endl;

    int dx = event->x() - lastPos.x();

    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        xRot = xRot + 8 * dy;
        yRot = yRot + 8 * dx;
    }
    lastPos = event->pos();
    updateGL();
}
