// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QDebug>
#include "figura.h"
#include "linea.h"

using namespace std;
#include "myglwidget.h"

int a = 0;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    probando = 0;
    error = new QErrorMessage(this);
    QVector3D *inicio = new QVector3D(0.0, 0.0, 0.0);
    QVector3D *fin = new QVector3D(0.0, 0.0, 0.0);
    QVector3D color = QVector3D(1.0, 0.0, 0.0);

    QVector<QVector3D*> opengl, pixel;
    opengl.push_back(inicio);
    opengl.push_back(fin);

    pixel<<inicio<<fin;


    figura* a = new linea(opengl, pixel, color);
    figuras.push_back(a);

}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(600, 600);
}

GLfloat MyGLWidget::PixelToOpenGLX(int x){
    cout<<GL_WINDOW_WIDTH<<endl;
    return  (GLfloat)((x<<1)-(GL_WINDOW_WIDTH-1))/(GL_WINDOW_WIDTH-1);

}
GLfloat MyGLWidget::PixelToOpenGLY(int y){
    return (GLfloat)((GL_WINDOW_HEIGHT-1)-(y<<1))/(GL_WINDOW_HEIGHT-1);
}
GLint MyGLWidget::OpenGLToPixelX(float x){
    return (GLint)(((GL_WINDOW_WIDTH-1)*(x+1)))>>1;
}
GLint MyGLWidget::OpenGLToPixelY(float y){
    return (GLint)((GL_WINDOW_HEIGHT-1)-((GL_WINDOW_HEIGHT-1)*y))>>1;
}


static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    /*
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
    */
}

void MyGLWidget::setYRotation(int angle)
{
    /*
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }*/
}

void MyGLWidget::spin_slot(int value){
    cout<<value<<endl;
    if(value > probando)
        emit spin_signal(value - 1);

}

void MyGLWidget::done_button_pressed_slot(void){
    cout<<"Esto es una prueba"<<endl;
}

void MyGLWidget::progress_bar_slot(int progress){
    cout<<"Progress Bar>> "<<progress<<endl;
}

void MyGLWidget::add_button_pressed_slot(){
    cout<<"Anadiendo Figura nueva"<<endl;
    probando+=1;
   /* QMessageBox messageBox;
    messageBox.critical(0,"Error","An error has occured !");*/

    /*
    QMessageBox msgBox;
     msgBox.setWindowTitle("Error!");
     msgBox.setText("Short description");
     msgBox.setDetailedText("Detailed error Information");
     msgBox.exec();
     */

    error->showMessage("This is a message");
}

/* Figures Slots */

void MyGLWidget::linea_button_pressed_slot(bool press){
    if(!press)
       cout<<"Linea desactiva "<<a++<<endl;
    else{
       cout<<"Linea activo"<<a++<<endl;
       emit progress_bar_signal(25);
    }cout<<"-----"<<endl;

}

void MyGLWidget::triangulo_button_pressed_slot(bool press){
    if(!press)
       cout<<"Triangulo desactiva "<<a++<<endl;
    else
       cout<<"Triangulo activo"<<a++<<endl;

}

void MyGLWidget::rectangulo_button_pressed_slot(bool press){
   if(!press)
      cout<<"Rectangulo desactiva "<<a++<<endl;
   else
      cout<<"Rectangulo activo"<<a++<<endl;

}

void MyGLWidget::elipse_button_pressed_slot(bool press){
    if(!press)
       cout<<"Elipse desactiva "<<a++<<endl;
    else
       cout<<"Elipse activo"<<a++<<endl;
}

/* Colors Slots */

void MyGLWidget::red_slider_slot(int number){
    figuras[0]->color.setX(((float)number)/255.0);
    updateGL();
}

void MyGLWidget::green_slider_slot(int number){
    figuras[0]->color.setY(((float)number)/255.0);
    updateGL();
}


void MyGLWidget::blue_slider_slot(int number){
    figuras[0]->color.setZ(((float)number)/255.0);
    updateGL();
}


void MyGLWidget::open_file_slot(){
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Abrir Archivo"),
                "C:\\Users\\Crema\\Desktop\\MyOpenGL\\modelos",
                "All files (*.*);;Off files (*,off)"
                );

     QMessageBox::information(this, tr("Archivo abierto"), filename);


    cout<<"filename: "<<filename.toStdString()<<endl;

}



void MyGLWidget::setZRotation(int angle)
{

    emit zRotationChanged(angle);
    updateGL();
    /*qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }*/
}

void MyGLWidget::setMyPrueba(int hola){

    cout<<hola<<endl;
    if(hola==50) {
        emit pruebaChanged(35);
        paintGL();
    }
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    //static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    //glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    //glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    //glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    cout<<"resizeGL>> w "<<width<<" h "<<height<<endl;

    GL_WINDOW_WIDTH = width;
    GL_WINDOW_HEIGHT = height;

    int side = qMin(width, height);
   // glViewport((width - side) / 2, (height - side) / 2, side, side);
  glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

#ifdef QT_OPENGL_ES_1
    glOrthof(-1, +1, -1, +1, 1.0, 15.0);
#else
    glOrtho(-1, +1, -1, +1, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
    cout<<"mousePressEvent"<<endl;

    figuras[0]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
    figuras[0]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));

    updateGL();

}

void MyGLWidget::mouseDoubleClickEvent(QMouseEvent *event){

    qDebug()<<"Doble Click>>";
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{

   figuras[0]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
   figuras[0]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));

    int dx = event->x() - lastPos.x();

    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
    updateGL();
}

void MyGLWidget::draw()
{
    for(int i=0;i<figuras.size();i++){
        figuras.at(i)->dibujar_figura();

    }

}
