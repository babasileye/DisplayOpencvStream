#ifndef QOPENCVWIDGET_H
#define QOPENCVWIDGET_H

#include  <opencv2/opencv.hpp>

#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QImage>

class QOpenCVWidget : public QWidget
{
public:

 QOpenCVWidget(QWidget *parent = 0);

 ~QOpenCVWidget();

 void mat2QImage(const cv::Mat & matImage);  // Convertir cv::Mat en QImage

 void putImage(cv::Mat image); // Cette fonction permettra de donner l'image à afficher par le label

private:
 /** Le label permet l'affichage d'image le plus rapide dans Qt
 c'est dans ce label que vont apparaitre les images de la camera*/
 QLabel *qLabel;

 // De objets pour la mise en page
 QVBoxLayout *layout;
 QHBoxLayout *hLayout;

 QImage qImage; // Image reçue de la camera
};

#endif // QOPENCVWIDGET_H
