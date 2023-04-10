#include <opencv2/opencv.hpp>


void detectHands(cv::Mat *frame){
    cv::Mat proc;
    cv::cvtColor(*frame,proc,cv::COLOR_BGRA2GRAY);
    *frame = proc;
    
}