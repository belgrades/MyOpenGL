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
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <myglwidget.h>
#include "widget3d.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    MyGLWidget *myGLWidget;
    widget3d *widget3D;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_10;
    QRadioButton *linea_button;
    QRadioButton *triangulo_button;
    QRadioButton *rectangulo_button;
    QRadioButton *elipse_button;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_12;
    QSlider *red_slider;
    QSlider *green_slider;
    QSlider *blue_slider;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QSpinBox *spin_box;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_6;
    QToolButton *toolButton_5;
    QToolButton *toolButton_7;
    QToolButton *done;
    QToolButton *toolButton_9;
    QToolButton *toolButton_8;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_15;
    QSlider *rotYSlider;
    QSlider *rotXSlider;
    QSlider *rotZSlider;
    QSlider *myPrueba;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *toolButton_10;
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QToolButton *abrir_archivo;
    QToolButton *toolButton_2;
    QToolButton *toolButton_11;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QStringLiteral("Window"));
        Window->resize(773, 495);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/seo-panda-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Window->setWindowIcon(icon);
        gridLayout = new QGridLayout(Window);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
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


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        linea_button = new QRadioButton(Window);
        linea_button->setObjectName(QStringLiteral("linea_button"));

        verticalLayout_10->addWidget(linea_button);

        triangulo_button = new QRadioButton(Window);
        triangulo_button->setObjectName(QStringLiteral("triangulo_button"));

        verticalLayout_10->addWidget(triangulo_button);

        rectangulo_button = new QRadioButton(Window);
        rectangulo_button->setObjectName(QStringLiteral("rectangulo_button"));

        verticalLayout_10->addWidget(rectangulo_button);

        elipse_button = new QRadioButton(Window);
        elipse_button->setObjectName(QStringLiteral("elipse_button"));

        verticalLayout_10->addWidget(elipse_button);

        radioButton = new QRadioButton(Window);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_10->addWidget(radioButton);


        horizontalLayout_7->addLayout(verticalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        red_slider = new QSlider(Window);
        red_slider->setObjectName(QStringLiteral("red_slider"));
        red_slider->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(red_slider->sizePolicy().hasHeightForWidth());
        red_slider->setSizePolicy(sizePolicy);
        red_slider->setAutoFillBackground(false);
        red_slider->setStyleSheet(QStringLiteral("background-color: red"));
        red_slider->setMaximum(255);
        red_slider->setValue(255);
        red_slider->setOrientation(Qt::Horizontal);
        red_slider->setTickPosition(QSlider::NoTicks);

        verticalLayout_12->addWidget(red_slider);

        green_slider = new QSlider(Window);
        green_slider->setObjectName(QStringLiteral("green_slider"));
        green_slider->setStyleSheet(QStringLiteral("background-color: green"));
        green_slider->setMaximum(255);
        green_slider->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(green_slider);

        blue_slider = new QSlider(Window);
        blue_slider->setObjectName(QStringLiteral("blue_slider"));
        blue_slider->setStyleSheet(QStringLiteral("background-color: blue"));
        blue_slider->setMaximum(255);
        blue_slider->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(blue_slider);


        horizontalLayout_7->addLayout(verticalLayout_12);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        progressBar = new QProgressBar(Window);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        spin_box = new QSpinBox(Window);
        spin_box->setObjectName(QStringLiteral("spin_box"));

        horizontalLayout->addWidget(spin_box);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton_6 = new QToolButton(Window);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon1);
        toolButton_6->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_6);

        toolButton_5 = new QToolButton(Window);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon2);
        toolButton_5->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_7 = new QToolButton(Window);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/Button-Add-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon3);
        toolButton_7->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_7);

        done = new QToolButton(Window);
        done->setObjectName(QStringLiteral("done"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/Button-Ok-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        done->setIcon(icon4);
        done->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(done);

        toolButton_9 = new QToolButton(Window);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/Button-Cancel-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon5);
        toolButton_9->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_9);

        toolButton_8 = new QToolButton(Window);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/Button-Refresh-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon6);
        toolButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(toolButton_8);


        verticalLayout_7->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_2 = new QLabel(Window);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        label_2->setWordWrap(false);
        label_2->setMargin(0);
        label_2->setIndent(0);

        verticalLayout_14->addWidget(label_2);

        label = new QLabel(Window);
        label->setObjectName(QStringLiteral("label"));
        label->setMargin(0);

        verticalLayout_14->addWidget(label);

        label_3 = new QLabel(Window);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_14->addWidget(label_3);

        label_4 = new QLabel(Window);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_14->addWidget(label_4);


        horizontalLayout_8->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        rotYSlider = new QSlider(Window);
        rotYSlider->setObjectName(QStringLiteral("rotYSlider"));
        rotYSlider->setMaximum(360);
        rotYSlider->setSingleStep(16);
        rotYSlider->setPageStep(15);
        rotYSlider->setOrientation(Qt::Horizontal);
        rotYSlider->setTickPosition(QSlider::TicksAbove);
        rotYSlider->setTickInterval(15);

        verticalLayout_15->addWidget(rotYSlider);

        rotXSlider = new QSlider(Window);
        rotXSlider->setObjectName(QStringLiteral("rotXSlider"));
        rotXSlider->setMaximum(360);
        rotXSlider->setSingleStep(16);
        rotXSlider->setPageStep(15);
        rotXSlider->setOrientation(Qt::Horizontal);
        rotXSlider->setTickPosition(QSlider::TicksAbove);
        rotXSlider->setTickInterval(15);

        verticalLayout_15->addWidget(rotXSlider);

        rotZSlider = new QSlider(Window);
        rotZSlider->setObjectName(QStringLiteral("rotZSlider"));
        rotZSlider->setMinimum(-100);
        rotZSlider->setMaximum(360);
        rotZSlider->setSingleStep(16);
        rotZSlider->setPageStep(15);
        rotZSlider->setOrientation(Qt::Horizontal);
        rotZSlider->setTickPosition(QSlider::TicksAbove);
        rotZSlider->setTickInterval(15);

        verticalLayout_15->addWidget(rotZSlider);

        myPrueba = new QSlider(Window);
        myPrueba->setObjectName(QStringLiteral("myPrueba"));
        myPrueba->setCursor(QCursor(Qt::SplitHCursor));
        myPrueba->setOrientation(Qt::Horizontal);
        myPrueba->setTickPosition(QSlider::TicksAbove);
        myPrueba->setTickInterval(1);

        verticalLayout_15->addWidget(myPrueba);


        horizontalLayout_8->addLayout(verticalLayout_15);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        toolButton_10 = new QToolButton(Window);
        toolButton_10->setObjectName(QStringLiteral("toolButton_10"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/Button-Info-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon7);
        toolButton_10->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_10);

        toolButton_3 = new QToolButton(Window);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon8);
        toolButton_3->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_3);

        toolButton = new QToolButton(Window);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon9);
        toolButton->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton);

        abrir_archivo = new QToolButton(Window);
        abrir_archivo->setObjectName(QStringLiteral("abrir_archivo"));
        abrir_archivo->setIcon(icon1);
        abrir_archivo->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(abrir_archivo);

        toolButton_2 = new QToolButton(Window);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setAcceptDrops(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/images/Actions-window-fullscreen-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon10);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonFollowStyle);

        horizontalLayout_9->addWidget(toolButton_2);

        toolButton_11 = new QToolButton(Window);
        toolButton_11->setObjectName(QStringLiteral("toolButton_11"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/images/Button-Turn-Off-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon11);
        toolButton_11->setIconSize(QSize(32, 32));

        horizontalLayout_9->addWidget(toolButton_11);


        verticalLayout_8->addLayout(horizontalLayout_9);


        horizontalLayout_4->addLayout(verticalLayout_8);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 5);


        retranslateUi(Window);
        QObject::connect(linea_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(linea_button_pressed_slot(bool)));
        QObject::connect(triangulo_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(triangulo_button_pressed_slot(bool)));
        QObject::connect(elipse_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(elipse_button_pressed_slot(bool)));
        QObject::connect(rectangulo_button, SIGNAL(toggled(bool)), myGLWidget, SLOT(rectangulo_button_pressed_slot(bool)));
        QObject::connect(progressBar, SIGNAL(valueChanged(int)), myGLWidget, SLOT(progress_bar_slot(int)));
        QObject::connect(abrir_archivo, SIGNAL(clicked()), myGLWidget, SLOT(open_file()));
        QObject::connect(done, SIGNAL(clicked()), myGLWidget, SLOT(done_button_pressed_slot()));
        QObject::connect(toolButton_7, SIGNAL(clicked()), myGLWidget, SLOT(add_button_pressed_slot()));
        QObject::connect(red_slider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(red_slider_slot(int)));
        QObject::connect(green_slider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(green_slider_slot(int)));
        QObject::connect(blue_slider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(blue_slider_slot(int)));
        QObject::connect(toolButton_6, SIGNAL(clicked()), myGLWidget, SLOT(open_file_slot()));
        QObject::connect(spin_box, SIGNAL(valueChanged(int)), myGLWidget, SLOT(spin_slot(int)));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Window", 0));
        linea_button->setText(QApplication::translate("Window", "L\303\255nea", 0));
        triangulo_button->setText(QApplication::translate("Window", "Tri\303\241ngulo", 0));
        rectangulo_button->setText(QApplication::translate("Window", "Rect\303\241ngulo", 0));
        elipse_button->setText(QApplication::translate("Window", "Elipse", 0));
        radioButton->setText(QApplication::translate("Window", "Bezier", 0));
        toolButton_6->setText(QApplication::translate("Window", "...", 0));
        toolButton_5->setText(QApplication::translate("Window", "...", 0));
        toolButton_7->setText(QApplication::translate("Window", "...", 0));
        done->setText(QApplication::translate("Window", "...", 0));
        toolButton_9->setText(QApplication::translate("Window", "...", 0));
        toolButton_8->setText(QApplication::translate("Window", "...", 0));
        label_2->setText(QApplication::translate("Window", "Y Rotation", 0));
        label->setText(QApplication::translate("Window", "X Rotation", 0));
        label_3->setText(QApplication::translate("Window", "Z Rotation", 0));
        label_4->setText(QApplication::translate("Window", "Prueba", 0));
        toolButton_10->setText(QApplication::translate("Window", "...", 0));
        toolButton_3->setText(QApplication::translate("Window", "...", 0));
        toolButton->setText(QApplication::translate("Window", "...", 0));
        abrir_archivo->setText(QApplication::translate("Window", "...", 0));
        toolButton_2->setText(QApplication::translate("Window", "...", 0));
        toolButton_11->setText(QApplication::translate("Window", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
