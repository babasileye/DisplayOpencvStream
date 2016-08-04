 #include "qopencvwidget.h"

// Constructor
 QOpenCVWidget::QOpenCVWidget(QWidget *parent) :
     QWidget(parent)
 {
     layout     = new QVBoxLayout;
     qLabel     = new QLabel;
     hLayout    = new QHBoxLayout;

     // initialisation du label avec une image créée de toute pièce
     QImage dummy(800,600,QImage::Format_RGB32);
     qImage = dummy;
     layout->addWidget(qLabel);
     for (int x = 0; x < 800; x ++)
       for (int y =0; y < 600; y++)
        qImage.setPixel(x,y,qRgb(x, y, y));

     qLabel->setPixmap(QPixmap::fromImage(qImage));

     hLayout->addLayout(layout);

     setLayout(hLayout);
 }

 QOpenCVWidget::~QOpenCVWidget()
 {
 }


 void QOpenCVWidget::putImage(cv::Mat matImage)
 {
     // On transforme l'image passée en parametre en QImage
     mat2QImage(matImage);

     // pour l'afficher dans notre label
     qLabel->setPixmap(QPixmap::fromImage(qImage.rgbSwapped()));
  }

 // Convertir IplImage en QImage
  void QOpenCVWidget::mat2QImage(const cv::Mat & matImage)
  {
     // QImage needs the data to be stored continuously in memory
     assert(matImage.isContinuous());

     // Assign OpenCV's image buffer to the QImage. Note that the bytesPerLine parameter
     // (http://qt-project.org/doc/qt-4.8/qimage.html#QImage-6) is 3*width because each pixel
     // has three bytes.

     qImage = QImage(matImage.data,matImage.cols,matImage.rows, QImage::Format_RGB888);
  }
