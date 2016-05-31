#ifndef WIDGET3D_H
#define WIDGET3D_H

#include <QGLWidget>
#include <iostream>
using namespace std;

class widget3d : public QGLWidget
{
    Q_OBJECT
public:
    explicit widget3d(QWidget *parent = 0);
    int GL_WINDOW_WIDTH, GL_WINDOW_HEIGHT;
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);


    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
signals:

public slots:

};

#endif // WIDGET3D_H
