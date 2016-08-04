#include "camerawindow.h"

CameraWindow::CameraWindow(const std::string cameraStreamUrl, QWidget *parent) :
    QWidget(parent)
{
    // ouverture du flux video de la camera
    camera.open(cameraStreamUrl.c_str());

    // Création de notre beau widget
    QVBoxLayout *layout = new QVBoxLayout;

    cvwidget = new QOpenCVWidget(this);

    layout->addWidget(cvwidget);

    setLayout(layout);

    resize(800, 600);

    // Demarage du timer qui appelle timerEvent() toute les 25 ms
    startTimer(25);
}


void CameraWindow::timerEvent(QTimerEvent*)
{
    camera.read(rgbImage);

    cv::Mat rgbResized;

    cv::resize(rgbImage, rgbResized,cv::Size(0.25*rgbImage.cols,0.25*rgbImage.rows));

    //imshow("test",rgbResized);

    cvwidget->putImage(rgbResized);
}
