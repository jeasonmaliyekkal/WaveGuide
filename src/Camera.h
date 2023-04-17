#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>

class Camera {
public:
    Camera();
    void setResolution(int width, int height);
    void captureFrame(cv::Mat& frame);
    void captureBackground(cv::Mat& background);
    ~Camera();
    cv::VideoCapture cap;
};

#endif
