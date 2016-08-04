#ifndef DISPLAYOPENCVSTREAM_H
#define DISPLAYOPENCVSTREAM_H

#include <QMainWindow>
#include <QWidget>
#include <QImage>
#include <QPainter>

#include <opencv2/opencv.hpp>

namespace Ui {
class DisplayOpencvStream;
}

class DisplayOpencvStream : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayOpencvStream(const std::string videoStreamUrl,QWidget *parent = 0);

    ~DisplayOpencvStream();

    QSize sizeHint() const;

    QSize minimumSizeHint() const;

public slots:

    // display the image
    void displayImage(const cv::Mat& image);

    // play video stream
    void playVideo();


private:

    void paintEvent(QPaintEvent* /*event*/);

    QImage _qimage;

    cv::Mat _tmp;

    Ui::DisplayOpencvStream *ui;

    std::string videoStreamUrl;
};

#endif // DISPLAYOPENCVSTREAM_H
