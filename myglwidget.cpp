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
#include "triangle.h"
#include "quad.h"
#include "ellipse.h"


using namespace std;
#include "myglwidget.h"

int a = 0;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    actual_figure = NONE;
    actual = -1;
    xRot = 0;
    yRot = 0;
    zRot = 0;
    probando = 0;
    error_loading = new QErrorMessage(this);
    done_message = new QErrorMessage(this);
    GL_WINDOW_HEIGHT = 600;
    GL_WINDOW_WIDTH = 600;
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

/* Special Buttons Slots*/

void MyGLWidget::progress_bar_slot(int progress){
    cout<<"Progress Bar>> "<<progress<<endl;
}

void MyGLWidget::spin_slot(int value){

    if(value > figuras.size() - 1)
        emit spin_signal(value - 1);
    else if(value != actual){
        if(figuras.size()>0 && !figuras[actual]->done){
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Figura no finalizada", "Desea finalizar, guardar la figura? Se seleccionará el índice seleccionado como actual.",
                                        QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                figuras[actual]->done = true;
                actual = value;
                figuras[actual]->done = false;
            } else {
                // Erase element not done
                figuras.removeAt(actual);

                // Set actual index to last element in figures
                actual =  value;

                // Undone actual
                figuras[actual]->done = false;

                // Modify spin to actual
                emit spin_signal(actual);
            }
        }else{
            // Undone actual
            actual = value;
            figuras[actual]->done = false;
        }
    }
}

void MyGLWidget::done_button_pressed_slot(void){
    cout<<"Figure done"<<endl;

    if(figuras.size()>0 && !figuras[actual]->done)
        figuras[actual]->done = true;
    else{
        QMessageBox msgBox;
            msgBox.setWindowTitle("Error!");
            msgBox.setText("No se pudo finalizar la figura.");
            msgBox.setDetailedText("1) No la ha creado. \n2) Ya ha sido finalizada.");
            msgBox.exec();
    }

    updateGL();
}

void MyGLWidget::add_button_pressed_slot()
{
    cout<<"Adding new figure"<<endl;

    QVector3D *inicio, *fin, color, *medio, *medio2;
    QVector<QVector3D*> opengl, pixel;
    figura* a;

    // Check if actual figure is not done
    if(figuras.size()>0 && !figuras[actual]->done){

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Figura no finalizada", "Desea finalizar y guardar la figura?",
                                    QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            figuras[actual]->done = true;
        } else {
            // Erase element not done
            figuras.removeAt(actual);

            // Set actual index to last element in figures
            actual = figuras.size()-1;

            // Modify spin to actual
            emit spin_signal(actual);
        }
    }

    switch(actual_figure){
        case NONE:
             error_loading->showMessage("Seleccione un tipo de figura para añadir");
        break;

        case LINE:
            cout<<"Adding line"<<endl;
            inicio = new QVector3D(0.0, 0.0, 0.0);
            fin = new QVector3D(0.0, 0.0, 0.0);
            color = QVector3D(1.0, 0.0, 0.0);

            emit change_red_slider(255);
            emit change_blue_slider(0);
            emit change_green_slider(0);

            opengl.push_back(inicio);
            opengl.push_back(fin);

            pixel<<inicio<<fin;

            a = new linea(opengl, pixel, color, LINE);
            figuras.push_back(a);

            // Set actual index to last element in figures
            actual = figuras.size()-1;

            // Modify spin to actual
            emit spin_signal(actual);
        break;

        case ELLIPSE:
            cout<<"Adding Ellipse"<<endl;
            cout<<"Adding line"<<endl;

            inicio = new QVector3D(0.0, 0.0, 0.0);
            fin = new QVector3D(0.0, 0.0, 0.0);
            color = QVector3D(1.0, 0.0, 0.0);

            emit change_red_slider(255);
            emit change_blue_slider(0);
            emit change_green_slider(0);

            opengl.push_back(inicio);
            opengl.push_back(fin);

            pixel<<inicio<<fin;

            a = new ellipse(opengl, pixel, color, ELLIPSE);
            a->GL_WINDOW_HEIGHT = GL_WINDOW_HEIGHT;
            a->GL_WINDOW_WIDTH = GL_WINDOW_WIDTH;
            figuras.push_back(a);

            // Set actual index to last element in figures
            actual = figuras.size()-1;

            // Modify spin to actual
            emit spin_signal(actual);
        break;

        case QUAD:
            cout<<"Adding Quad"<<endl;

            // Figure Points
            inicio = new QVector3D(0.0, 0.0, 0.0);
            medio = new QVector3D(0.0, 0.0, 0.0);
            medio2 = new QVector3D(0.0, 0.0, 0.0);
            fin = new QVector3D(0.0, 0.0, 0.0);

            // Figure color
            color = QVector3D(1.0, 0.0, 0.0);

            emit change_red_slider(255);
            emit change_blue_slider(0);
            emit change_green_slider(0);

            opengl.push_back(inicio);
            opengl.push_back(medio);
            opengl.push_back(medio2);
            opengl.push_back(fin);

            pixel<<inicio<<medio<<medio2<<fin;

            a = new quad(opengl, pixel, color, QUAD);

            figuras.push_back(a);

            // Set actual index to last element in figures
            actual = figuras.size()-1;

            // Modify spin to actual
            emit spin_signal(actual);
        break;

        case TRIANGLE:
            cout<<"Adding Triangle"<<endl;

            // Points of triangle
            inicio = new QVector3D(0.0, 0.0, 0.0);
            medio = new QVector3D(0.0, 0.0, 0.0);
            fin = new QVector3D(0.0, 0.0, 0.0);

            color = QVector3D(1.0, 0.0, 0.0);

            emit change_red_slider(255);
            emit change_blue_slider(0);
            emit change_green_slider(0);

            opengl.push_back(inicio);
            opengl.push_back(medio);
            opengl.push_back(fin);

            pixel<<inicio<<medio<<fin;

            a = new triangle(opengl, pixel, color, TRIANGLE);
            figuras.push_back(a);

            // Set actual index to last element in figures
            actual = figuras.size()-1;

            // Modify spin to actual
            emit spin_signal(actual);

        break;

        case BEZIER:
            cout<<"Adding Bezier"<<endl;
        break;
    }

    updateGL();
}

/* Figures Slots */

void MyGLWidget::linea_button_pressed_slot(bool press)
{
    if(!press)
       cout<<"Linea desactiva "<<a++<<endl;
    else{
       cout<<"Linea activo"<<a++<<endl;
       actual_figure = LINE;
       emit progress_bar_signal(25);
    }
}

void MyGLWidget::triangulo_button_pressed_slot(bool press)
{
    if(!press)
       cout<<"Triangulo desactiva "<<a++<<endl;
    else
       actual_figure = TRIANGLE;

}

void MyGLWidget::rectangulo_button_pressed_slot(bool press)
{
   if(!press)
      cout<<"Rectangulo desactiva "<<a++<<endl;
   else
      actual_figure = QUAD;

}

void MyGLWidget::elipse_button_pressed_slot(bool press)
{
    if(!press)
       cout<<"Elipse desactiva "<<a++<<endl;
    else
       actual_figure = ELLIPSE;
}

/* Colors Slots */

void MyGLWidget::red_slider_slot(int number)
{
    if(figuras.size()>0 && !figuras[actual]->done)
        figuras[actual]->color.setX(((float)number)/255.0);

    updateGL();
}


void MyGLWidget::green_slider_slot(int number)
{
    if(figuras.size()>0 && !figuras[actual]->done)
        figuras[actual]->color.setY(((float)number)/255.0);
    updateGL();
}

void MyGLWidget::blue_slider_slot(int number)
{
    if(figuras.size()>0 && !figuras[actual]->done)
        figuras[actual]->color.setZ(((float)number)/255.0);
    updateGL();
}

/* Open file slot */

void MyGLWidget::open_file_slot()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Abrir Archivo"),
                "C:\\Users\\Crema\\Desktop\\MyOpenGL\\modelos",
                "All files (*.*);;Off files (*,off)"
                );

     QMessageBox::information(this, tr("Archivo abierto"), filename);

    cout<<"filename: "<<filename.toStdString()<<endl;
}

/* OpenGL Abstract Methods */

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

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    cout<<"mousePressEvent"<<endl;
    if(figuras.size()>0 && !figuras[actual]->done){
        switch(figuras[actual]->my_type){
            case NONE:
                 error_loading->showMessage("Seleccione un tipo de figura para añadir");
            break;

            case LINE:
                // First point should be initialize
                if(figuras[actual]->initialize){
                    figuras[actual]->puntos_control_opengl[0]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[0]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->initialize = false;
                }

                // Modify the second point
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));

            break;

            case ELLIPSE:
                cout<<"Adding Ellipse"<<endl;
                // First point should be initialize
                if(figuras[actual]->initialize){
                    figuras[actual]->puntos_control_opengl[0]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[0]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->initialize = false;
                }

                // Modify the second point
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
            break;

            case QUAD:
                cout<<"Adding Quad"<<endl;
                // First point should be initialize
                if(figuras[actual]->initialize){
                    figuras[actual]->puntos_control_opengl[0]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[0]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->initialize = false;
                }

                // Modify the second point
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
            break;

            case TRIANGLE:
                // First point should be initialize
                if(figuras[actual]->initialize){
                    figuras[actual]->puntos_control_opengl[0]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[0]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->initialize = false;
                }

                if(!figuras[actual]->stage){
                    // Modify the second point
                    figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->puntos_control_opengl[2]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[2]->setY(PixelToOpenGLY(event->y()));
                }else{
                    figuras[actual]->puntos_control_opengl[2]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[2]->setY(PixelToOpenGLY(event->y()));
                }
            break;

            case BEZIER:
                cout<<"Adding Bezier"<<endl;
            break;
        }
    }
    updateGL();

}

void MyGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"Doble Click>>";
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(figuras.size()>0 && !figuras[actual]->done){
        switch(figuras[actual]->my_type){
            case NONE:
                 error_loading->showMessage("Seleccione un tipo de figura para añadir");
            break;

            case LINE:
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
            break;

            case ELLIPSE:
                cout<<"Adding Ellipse"<<endl;
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
            break;

            case QUAD:
                cout<<"Adding Quad"<<endl;
                figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
            break;

            case TRIANGLE:
                cout<<"Triangle"<<endl;
                if(!figuras[actual]->stage){
                    // Modify the second point
                    figuras[actual]->puntos_control_opengl[1]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[1]->setY(PixelToOpenGLY(event->y()));
                    figuras[actual]->puntos_control_opengl[2]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[2]->setY(PixelToOpenGLY(event->y()));
                }else{
                    figuras[actual]->puntos_control_opengl[2]->setX(PixelToOpenGLX(event->x()));
                    figuras[actual]->puntos_control_opengl[2]->setY(PixelToOpenGLY(event->y()));
                }
            break;

            case BEZIER:
                cout<<"Adding Bezier"<<endl;
            break;
        }
    }
    updateGL();
}

void MyGLWidget::draw()
{
    glPolygonMode(GL_FRONT,GL_LINE);
    glPolygonMode(GL_BACK,GL_LINE);
    for(int i=0;i<figuras.size();i++){
        if(!figuras[i]->initialize)
            figuras[i]->dibujar_figura();
    }
}

void MyGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(figuras.size()>0 && !figuras[actual]->done){
        switch(figuras[actual]->my_type){
            case NONE:
                 error_loading->showMessage("Seleccione un tipo de figura para añadir");
            break;

            case LINE:

            break;

            case ELLIPSE:
                cout<<"Adding Ellipse"<<endl;
            break;

            case QUAD:
                cout<<"Adding Quad"<<endl;
            break;

            case TRIANGLE:
                cout<<"Triangle"<<endl;
                figuras[actual]->stage = 1;

            break;

            case BEZIER:
                cout<<"Adding Bezier"<<endl;
            break;
        }
    }
    updateGL();
}

void MyGLWidget::resizeGL(int width, int height)
{

    GL_WINDOW_WIDTH = width;

    for(int i=0; i<figuras.size(); i++){
        figuras[i]->GL_WINDOW_HEIGHT = height;
        figuras[i]->GL_WINDOW_WIDTH = width;
    }

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
