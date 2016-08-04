#ifndef CAMERAWINDOW_H
#define CAMERAWINDOW_H

#include "stdio.h"
#include <iostream>
#include <cstdio>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

#include <opencv2/opencv.hpp>

#include "qopencvwidget.h"

class CameraWindow : public QWidget
{
  Q_OBJECT

private:

  QOpenCVWidget *cvwidget;

  cv::VideoCapture camera; // Cet objet opencv permet de traiter le flux de la camera

  cv::Mat rgbImage;

public:

 CameraWindow(const std::string cameraStreamUrl, QWidget *parent=0); // constructor

 void timerEvent(QTimerEvent*); // Affiche l'image provenant de l'objet camera
};

#endif // CAMERAWINDOW_H
