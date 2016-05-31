/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <myglwidget.h>
#include "widget3d.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout;
    QLCDNumber *numero_figuras;
    QRadioButton *linea_button;
    QRadioButton *radioButton;
    QRadioButton *triangulo_button;
    QSlider *myPrueba;
    QProgressBar *progressBar;
    QSlider *rotYSlider;
    QRadioButton *elipse_button;
    QRadioButton *rectangulo_button;
    QHBoxLayout *horizontalLayout_6;
    MyGLWidget *myGLWidget;
    widget3d *widget3D;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolButton_3;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton;
    QToolButton *abrir_archivo;
    QToolButton *toolButton_2;
    QSlider *rotZSlider;
    QSlider *rotXSlider;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_7;
    QToolButton *done;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(568, 427);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/seo-panda-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Window);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        numero_figuras = new QLCDNumber(Window);
        numero_figuras->setObjectName(QStringLiteral("numero_figuras"));
        numero_figuras->setLayoutDirection(Qt::LeftToRight);
        numero_figuras->setAutoFillBackground(true);
        numero_figuras->setFrameShape(QFrame::StyledPanel);
        numero_figuras->setFrameShadow(QFrame::Sunken);
        numero_figuras->setLineWidth(2);
        numero_figuras->setMidLineWidth(0);

        gridLayout->addWidget(numero_figuras, 7, 1, 1, 1);

        linea_button = new QRadioButton(Window);
        linea_button->setObjectName(QStringLiteral("linea_button"));

        gridLayout->addWidget(linea_button, 2, 0, 1, 1);

        radioButton = new QRadioButton(Window);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout->addWidget(radioButton, 7, 0, 1, 1);

        triangulo_button = new QRadioButton(Window);
        triangulo_button->setObjectName(QStringLiteral("triangulo_button"));

        gridLayout->addWidget(triangulo_button, 3, 0, 1, 1);

        myPrueba = new QSlider(Window);
        myPrueba->setObjectName(QStringLiteral("myPrueba"));
        myPrueba->setCursor(QCursor(Qt::SplitHCursor));
        myPrueba->setOrientation(Qt::Horizontal);
        myPrueba->setTickPosition(QSlider::TicksAbove);
        myPrueba->setTickInterval(1);

        gridLayout->addWidget(myPrueba, 5, 5, 1, 1);

        progressBar = new QProgressBar(Window);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 7, 4, 1, 2);

        rotYSlider = new QSlider(Window);
        rotYSlider->setObjectName(QStringLiteral("rotYSlider"));
        rotYSlider->setMaximum(360);
        rotYSlider->setSingleStep(16);
        rotYSlider->setPageStep(15);
        rotYSlider->setOrientation(Qt::Horizontal);
        rotYSlider->setTickPosition(QSlider::TicksAbove);
        rotYSlider->setTickInterval(15);

        gridLayout->addWidget(rotYSlider, 2, 5, 1, 1);

        elipse_button = new QRadioButton(Window);
        elipse_button->setObjectName(QStringLiteral("elipse_button"));

        gridLayout->addWidget(elipse_button, 5, 0, 1, 1);

        rectangulo_button = new QRadioButton(Window);
        rectangulo_button->setObjectName(QStringLiteral("rectangulo_button"));

        gridLayout->addWidget(rectangulo_button, 4, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QStringLiteral("myGLWidget"));
        myGLWidget->setEnabled(true);
        myGLWidget->setMinimumSize(QSize(200, 200));
        myGLWidget->setCursor(QCursor(Qt::CrossCursor));

        horizontalLayout_6->addWidget(myGLWidget);

        widget3D = new widget3d(Window);
        widget3D->setObjectName(QStringLiteral("widget3D"));
        widget3D->setMinimumSize(QSize(200, 200));

        horizontalLayout_6->addWidget(widget3D);


        gridLayout->addLayout(horizontalLayout_6, 1, 0, 1, 7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        toolButton_3 = new QToolButton(Window);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon1);
        toolButton_3->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_3);

        toolButton_10 = new QToolButton(Window);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/Button-Info-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon2);
        toolButton_10->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_10);

        toolButton_11 = new QToolButton(Window);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/Button-Turn-Off-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon3);
        toolButton_11->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_11);

        toolButton = new QToolButton(Window);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton);

        abrir_archivo = new QToolButton(Window);
        abrir_archivo->setObjectName(QStringLiteral("abrir_archivo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        abrir_archivo->setIcon(icon5);
        abrir_archivo->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(abrir_archivo);

        toolButton_2 = new QToolButton(Window);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setAcceptDrops(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/Actions-window-fullscreen-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon6);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        horizontalLayout_9->addWidget(toolButton_2);


        gridLayout->addLayout(horizontalLayout_9, 9, 4, 1, 3);

        rotZSlider = new QSlider(Window);
        rotZSlider->setObjectName(QStringLiteral("rotZSlider"));
        rotZSlider->setMinimum(-100);
        rotZSlider->setMaximum(360);
        rotZSlider->setSingleStep(16);
        rotZSlider->setPageStep(15);
        rotZSlider->setOrientation(Qt::Horizontal);
        rotZSlider->setTickPosition(QSlider::TicksAbove);
        rotZSlider->setTickInterval(15);

        gridLayout->addWidget(rotZSlider, 4, 5, 1, 1);

        rotXSlider = new QSlider(Window);
        rotXSlider->setObjectName(QStringLiteral("rotXSlider"));
        rotXSlider->setMaximum(360);
        rotXSlider->setSingleStep(16);
        rotXSlider->setPageStep(15);
        rotXSlider->setOrientation(Qt::Horizontal);
        rotXSlider->setTickPosition(QSlider::TicksAbove);
        rotXSlider->setTickInterval(15);

        gridLayout->addWidget(rotXSlider, 3, 5, 1, 1);

        horizontalSlider = new QSlider(Window);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QStringLiteral("background-color: red"));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(255);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton_6 = new QToolButton(Window);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setIcon(icon5);
        toolButton_6->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_6);

        toolButton_5 = new QToolButton(Window);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon7);
        toolButton_5->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_7 = new QToolButton(Window);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/Button-Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon8);
        toolButton_7->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_7);

        done = new QToolButton(Window);
        done->setObjectName(QStringLiteral("done"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/Button-Ok-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        done->setIcon(icon9);
        done->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(done);

        toolButton_8 = new QToolButton(Window);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/Button-Refresh-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon10);
        toolButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_8);

        toolButton_9 = new QToolButton(Window);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/Button-Cancel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon11);
        toolButton_9->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_9);


        gridLayout->addLayout(horizontalLayout_2, 9, 0, 1, 2);

        horizontalSlider_3 = new QSlider(Window);
        horizontalSlider_3->setObjectName(QStringLiteral("horizontalSlider_3"));
        horizontalSlider_3->setStyleSheet(QStringLiteral("background-color: blue"));
        horizontalSlider_3->setMaximum(255);
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_3, 4, 1, 1, 1);

        horizontalSlider_2 = new QSlider(Window);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setStyleSheet(QStringLiteral("background-color: green"));
        horizontalSlider_2->setMaximum(255);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 3, 1, 1, 1);

        label_4 = new QLabel(Window);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 4, 1, 1);

        label_3 = new QLabel(Window);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 4, 1, 1);

        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));
        label->setMargin(0);

        gridLayout->addWidget(label, 3, 4, 1, 1);

        label_2 = new QLabel(Window);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2->setWordWrap(false);
        label_2->setMargin(0);
        label_2->setIndent(0);

        gridLayout->addWidget(label_2, 2, 4, 1, 1);


        retranslateUi(Window);
        QObject::connect(rotXSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setXRotation(int)));
        QObject::connect(rotYSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setYRotation(int)));
        QObject::connect(rotZSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setZRotation(int)));
        QObject::connect(myPrueba, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setMyPrueba(int)));
        QObject::connect(linea_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(linea_button_pressed_slot(bool)));
        QObject::connect(triangulo_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(triangulo_button_pressed_slot(bool)));
        QObject::connect(elipse_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(elipse_button_pressed_slot(bool)));
        QObject::connect(rectangulo_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(rectangulo_button_pressed_slot(bool)));
        QObject::connect(progressBar, SIGNAL(valueChanged(int)), myGLWidget, SLOT(progress_bar_slot(int)));
        QObject::connect(myPrueba, SIGNAL(valueChanged(int)), numero_figuras, SLOT(display(int)));
        QObject::connect(abrir_archivo, SIGNAL(clicked()), myGLWidget, SLOT(open_file()));
        QObject::connect(done, SIGNAL(clicked()), myGLWidget, SLOT(done_button_pressed_slot()));
        QObject::connect(toolButton_7, SIGNAL(clicked()), myGLWidget, SLOT(add_button_pressed_slot()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(red_slider_slot(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), myGLWidget, SLOT(green_slider_slot(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), myGLWidget, SLOT(blue_slider_slot(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        linea_button->setText(QApplication::translate("Window", "L\303\255nea", 0));
        radioButton->setText(QApplication::translate("Window", "Bezier", 0));
        triangulo_button->setText(QApplication::translate("Window", "Tri\303\241ngulo", 0));
        elipse_button->setText(QApplication::translate("Window", "Elipse", 0));
        rectangulo_button->setText(QApplication::translate("Window", "Rect\303\241ngulo", 0));
        toolButton_3->setText(QApplication::translate("Window", "...", 0));
        toolButton_10->setText(QApplication::translate("Window", "...", 0));
        toolButton_11->setText(QApplication::translate("Window", "...", 0));
        toolButton->setText(QApplication::translate("Window", "...", 0));
        abrir_archivo->setText(QApplication::translate("Window", "...", 0));
        toolButton_2->setText(QApplication::translate("Window", "...", 0));
        toolButton_6->setText(QApplication::translate("Window", "...", 0));
        toolButton_5->setText(QApplication::translate("Window", "...", 0));
        toolButton_7->setText(QApplication::translate("Window", "...", 0));
        done->setText(QApplication::translate("Window", "...", 0));
        toolButton_8->setText(QApplication::translate("Window", "...", 0));
        toolButton_9->setText(QApplication::translate("Window", "...", 0));
        label_4->setText(QApplication::translate("Window", "Prueba", 0));
        label_3->setText(QApplication::translate("Window", "zRot", 0));
        label->setText(QApplication::translate("Window", "xRot", 0));
        label_2->setText(QApplication::translate("Window", "yrot", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
