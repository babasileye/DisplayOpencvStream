#-------------------------------------------------
#
# Project created by QtCreator 2016-07-13T15:15:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DisplayOpencvStream
TEMPLATE = app


SOURCES += main.cpp\
    qopencvwidget.cpp \
    camerawindow.cpp

HEADERS  += \
    camerawindow.h \
    qopencvwidget.h

FORMS    += displayopencvstream.ui

INCLUDEPATH += $$_PRO_FILE_PWD_

INCLUDEPATH += C:/Users/siley/Coding/VideoStitch-all/external_deps/include/


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_core310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_core310d

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/release/ -lopencv_imgproc310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/debug/ -lopencv_imgproc310d

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/release/ -lopencv_imgcodecs310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/debug/ -lopencv_imgcodecs310d

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_highgui310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_highgui310d

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/release/ -lopencv_videoio310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/debug/ -lopencv_videoio310

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/release/ -lopencv_video310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/debug/ -lopencv_video310

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_flann310
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release/ -lopencv_flann310d

INCLUDEPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
DEPENDPATH += $$PWD/../../../../tools/opencv-3.1.0/Build/lib/Release
