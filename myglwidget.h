// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QLCDNumber>
#include "figura.h"
#include "linea.h"
#include "figure_type.h"
#include <vector>
using namespace std;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:

    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
    int GL_WINDOW_WIDTH, GL_WINDOW_HEIGHT;
   int a;
   int probando;
   QVector<figura*> figuras;

protected:
    /**Methods Pixel -> GL ; GL -> Pixel**/
    GLfloat PixelToOpenGLX(int x);
    GLfloat PixelToOpenGLY(int y);
    GLint OpenGLToPixelX(float x);
    GLint OpenGLToPixelY(float y);

    /* Actual Figure */
    figureType actual_figure;
    int actual;

    QErrorMessage *error_loading;

    /**OpenGL virtual methods**/
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
    // Slots for buttons
    void linea_button_pressed_slot(bool press);
    void triangulo_button_pressed_slot(bool press);
    void rectangulo_button_pressed_slot(bool press);
    void elipse_button_pressed_slot(bool press);
    void done_button_pressed_slot(void);
    void spin_slot(int value);

    void red_slider_slot(int number);
    void blue_slider_slot(int number);
    void green_slider_slot(int number);

    void add_button_pressed_slot();
    void open_file_slot();

    //Slot for progress bar
    void progress_bar_slot(int progress);

signals:
    // signaling rotation from mouse movement
    void linea_button_pressed_signal(bool press);
    void progress_bar_signal(int progress);
    void spin_signal(int value);

private:
    void draw();

    int xRot;
    int yRot;
    int zRot;

    QPoint lastPos;
};

#endif // MYGLWIDGET_H

