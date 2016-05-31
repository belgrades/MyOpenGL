// window.cpp

#include <QtWidgets>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"

Window::Window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    connect(ui->myGLWidget, SIGNAL(xRotationChanged(int)), ui->rotXSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(yRotationChanged(int)), ui->rotYSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(zRotationChanged(int)), ui->rotZSlider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(pruebaChanged(int)), ui->myPrueba, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(progress_bar_signal(int)), ui->progressBar, SLOT(setValue(int)));
    //connect(ui->myGLWidget, SIGNAL(linea_button_pressed_signal(bool)), ui->linea_button, SLOT(linea_button_pressed_slot(bool)));
}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}
