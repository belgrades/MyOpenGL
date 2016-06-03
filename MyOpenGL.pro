#-------------------------------------------------
#
# Project created by QtCreator 2013-09-25T09:11:42
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    myglwidget.cpp \
    figura.cpp\
    widget3d.cpp \
    linea.cpp


HEADERS  += window.h \
    myglwidget.h \
    figura.h\
    widget3d.h \
    linea.h \
    figure_type.h


FORMS    += window.ui

RESOURCES += \
    application.qrc
