#include <iostream>
#include <cstdio>

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>

#include  <opencv2/opencv.hpp>

#include "qopencvwidget.h"
#include "camerawindow.h"

int main(int argc, char *argv[])
{
    std::string cameraStreamUrl("rtmp://10.0.0.66:1935/inputs/0_0");

    QApplication app(argc, argv);

    CameraWindow *mainWindow = new CameraWindow(cameraStreamUrl.c_str());

    mainWindow->setWindowTitle(cameraStreamUrl.c_str());

    mainWindow->show();

    return app.exec();
}
