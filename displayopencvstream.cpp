#include "displayopencvstream.h"
#include "ui_displayopencvstream.h"

DisplayOpencvStream::DisplayOpencvStream(const std::string videoStreamUrl,QWidget *parent) :
    videoStreamUrl(videoStreamUrl),
    QMainWindow(parent),
    ui(new Ui::DisplayOpencvStream)
{
    ui->setupUi(this);
}

DisplayOpencvStream::~DisplayOpencvStream()
{
    delete ui;
}

QSize DisplayOpencvStream::sizeHint() const
{
    return _qimage.size();
}

QSize DisplayOpencvStream::minimumSizeHint() const
{
    return _qimage.size();
}

void DisplayOpencvStream::displayImage(const cv::Mat& image)
{
    // Convert the image to the RGB888 format
    switch (image.type())
    {
        case CV_8UC1:
            cv::cvtColor(image, _tmp, CV_GRAY2RGB);
            break;
        case CV_8UC3:
            cv::cvtColor(image, _tmp, CV_BGR2RGB);
            break;
    }

   // QImage needs the data to be stored continuously in memory
   assert(_tmp.isContinuous());

   // Assign OpenCV's image buffer to the QImage. Note that the bytesPerLine parameter
   // (http://qt-project.org/doc/qt-4.8/qimage.html#QImage-6) is 3*width because each pixel
   // has three bytes.

   _qimage = QImage(_tmp.data, _tmp.cols, _tmp.rows, _tmp.cols*3, QImage::Format_RGB888);

   this->setFixedSize(image.cols, image.rows);

   repaint();
}

// Display the image
void DisplayOpencvStream::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0,0), _qimage);
    painter.end();
}

// play video stream
void DisplayOpencvStream::playVideo()
{
    cv::VideoCapture capture;

    bool isStream = capture.open(videoStreamUrl);

    cv::Mat rgb;

    cv::Mat resizedRgb;

    while (isStream && cv::waitKey(40)!=27)
    {
        bool isFrame = capture.read(rgb);

        if (isFrame)
        {
            cv::resize(rgb,resizedRgb,cv::Size(0.25*rgb.cols,0.25*rgb.rows));

            cv::imshow(videoStreamUrl,resizedRgb);

            displayImage(resizedRgb);
        }
    }

    cv::destroyWindow(videoStreamUrl);
}
