#include <opencv2/opencv.hpp>
#include<X11/Xlib.h>

using namespace cv;

void detectHands(cv::Mat *frame){

    // Convert the frame from RGB to HSV color space
    Mat hsv;
    cvtColor(*frame, hsv, COLOR_BGR2HSV);

    // Threshold the Hue and Saturation channels to segment skin pixels
    Mat skinMask;
    inRange(hsv, Scalar(0, 20, 70), Scalar(20, 255, 255), skinMask);

    // Apply morphological operations to the binary mask
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(7, 7));
    morphologyEx(skinMask, skinMask, MORPH_OPEN, kernel);
    morphologyEx(skinMask, skinMask, MORPH_CLOSE, kernel);

    // Apply the binary mask to the input frame
    Mat result;
    frame->copyTo(result, skinMask);
    *frame = result;


    // cv::Mat proc;
    // cv::cvtColor(*frame,proc,cv::COLOR_BGRA2GRAY);
    // *frame = proc;
    
}

void setCursor(int x, int y){
  Display *dpy = XOpenDisplay(NULL); // open the default display
  Window root = DefaultRootWindow(dpy); // get the root window
  XWarpPointer(dpy, None, root, 0, 0, 0, 0, x, y); // move the pointer
  XCloseDisplay(dpy);
}

