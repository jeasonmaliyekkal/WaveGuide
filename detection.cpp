#include <opencv2/opencv.hpp>
#include<X11/Xlib.h>

void detectHands(cv::Mat *frame){
    cv::Mat proc;
    cv::cvtColor(*frame,proc,cv::COLOR_BGRA2GRAY);
    *frame = proc;
    
}

void setCursor(int x, int y){
  Display *dpy = XOpenDisplay(NULL); // open the default display
  Window root = DefaultRootWindow(dpy); // get the root window
  XWarpPointer(dpy, None, root, 0, 0, 0, 0, x, y); // move the pointer
  XCloseDisplay(dpy);
}