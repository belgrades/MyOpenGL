// main.cpp

#include <QApplication>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QTimer>

#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/Crema/Desktop/MyOpenGL/logo.png"));
    splash->show();

    QTimer::singleShot(3000, splash, SLOT(close()));

    Window window;
    window.resize(window.sizeHint());
    int desktopArea = QApplication::desktop()->width() *
                      QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();

    window.setWindowTitle("CG Postgrado");

    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        QTimer::singleShot(3000, &window, SLOT(show()));
    else
        window.showMaximized();
    return app.exec();
}
