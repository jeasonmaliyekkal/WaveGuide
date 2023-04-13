#include <opencv2/opencv.hpp>
#include<X11/Xlib.h>

using namespace cv;

Mat detectHands(Mat *frame,Mat *background){
    Mat one,two;
    // // Convert the frame from RGB to HSV color space
    // Mat hsv;
    // cvtColor(*frame, hsv, COLOR_BGR2HSV);

    // // Threshold the Hue and Saturation channels to segment skin pixels
    // Mat skinMask;
    // inRange(hsv, Scalar(0, 20, 70), Scalar(20, 255, 255), skinMask);
    // // inRange(hsv, Scalar(0, 10, 60), Scalar(20, 150, 255), skinMask);


    // // Apply morphological operations to the binary mask
    // Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    
    // morphologyEx(skinMask, skinMask, MORPH_OPEN, kernel);
    // morphologyEx(skinMask, skinMask, MORPH_CLOSE, kernel);

    // // Apply the binary mask to the input frame
    // Mat result;
    // frame->copyTo(result, skinMask);
    // *frame = result;cv::CascadeClassifier palm_cascade;
    cvtColor(*frame, one, COLOR_BGR2GRAY);
    cvtColor(*background, two, COLOR_BGR2GRAY);
    Mat diff;
    absdiff(two, one, diff);

    // Convert the difference image to binary
    Mat bin;
    threshold(diff, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);







    return bin;

    
}

void setCursor(int x, int y){
  Display *dpy = XOpenDisplay(NULL); // open the default display
  Window root = DefaultRootWindow(dpy); // get the root window
  XWarpPointer(dpy, None, root, 0, 0, 0, 0, x, y); // move the pointer
  XCloseDisplay(dpy);
}

