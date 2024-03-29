#ifndef DETECT_HANDS_H
#define DETECT_HANDS_H

#include <opencv2/opencv.hpp>
#include "Mouse.h"

using namespace cv;

class HandDetector {
private:
    cv::Mat background;
public:
    HandDetector();
    void setBackground(cv::Mat bg);
    void detectHands(cv::Mat *frame, cv::Mat *bin);
};

#endif