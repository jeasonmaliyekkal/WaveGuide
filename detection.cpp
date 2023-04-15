#include <opencv2/opencv.hpp>
#include<X11/Xlib.h>
#include <X11/extensions/XTest.h>

using namespace cv;


void setCursor(int x, int y){
  Display *dpy = XOpenDisplay(NULL); // open the default display
  Window root = DefaultRootWindow(dpy); // get the root window
  XWarpPointer(dpy, None, root, 0, 0, 0, 0, x, y); // move the pointer
  XCloseDisplay(dpy);
}

void click(int button, bool state){
    Display* dpy = XOpenDisplay(NULL);
    // button = left mouse button and button = 2 for middle button and button = 3 for right button.
    // state = True implies button press, state = false implies button release
    XTestFakeButtonEvent(dpy, button, state, 0); // Press or Release Mouse Button
    
    
}


Point detectHands(Mat *frame,Mat *background,Mat *binn){
    Mat one,two;
    cvtColor(*frame, one, COLOR_BGR2GRAY);
    cvtColor(*background, two, COLOR_BGR2GRAY);
    Mat diff;
    absdiff(two, one, diff);
    // subtract(two, one, diff);
    
    

    // Convert the difference image to binary
    Mat bin;
    threshold(diff, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
    
     
    *binn = bin;
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Find the contour with the largest area
    double maxArea = 0;
    int maxAreaIdx = -1;
    for(int i = 0; i < contours.size(); i++){
        double area = contourArea(contours[i]);
        if(area > maxArea){
            maxArea = area;
            maxAreaIdx = i;
        }
    }

    // Create a convex hull from the largest contour
    std::vector<int> hullIndices;
    convexHull(contours[maxAreaIdx], hullIndices);

    // Draw the convex hull on the originalimage
    drawContours(*frame, std::vector<std::vector<Point>>{contours[maxAreaIdx]}, -1, Scalar(0, 0, 255), 2);
    std::vector<Point> hullPoints;
    for(int i = 0; i < hullIndices.size(); i++){
        hullPoints.push_back(contours[maxAreaIdx][hullIndices[i]]);
    }

    Point topPoint = hullPoints[0];
    for (int i = 1; i < hullPoints.size(); i++) {
        if (hullPoints[i].y < topPoint.y) {
            topPoint = hullPoints[i];
        }
    }

    int verts = hullPoints.size();

    // The top point's x and y coordinates can be accessed as follows:
    int topX = topPoint.x;
    int topY = topPoint.y;

    std::string text = "Top point: (" + std::to_string(topX) + ", " + std::to_string(topY) + ")";
    


    // Print the text onto the frame
    putText(*frame, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);
    
    drawContours(*frame, std::vector<std::vector<Point>>{hullPoints}, -1, Scalar(0, 255, 0), 2);

    return topPoint;

    
}



