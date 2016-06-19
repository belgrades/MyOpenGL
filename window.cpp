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
    connect(ui->myGLWidget, SIGNAL(spin_signal(int)), ui->spin_box, SLOT(setValue(int)));

    // Connections for color sliders, left panel
    connect(ui->myGLWidget, SIGNAL(change_blue_slider(int)), ui->blue_slider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(change_green_slider(int)), ui->green_slider, SLOT(setValue(int)));
    connect(ui->myGLWidget, SIGNAL(change_red_slider(int)), ui->red_slider, SLOT(setValue(int)));

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
