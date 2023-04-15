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
    XFlush(dpy);
    XCloseDisplay(dpy);
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

    // Find the angle between each pair of adjacent points on the convex hull
    std::vector<double> angles;
    for (int i = 0; i < hullPoints.size(); i++) {
        Point p1 = hullPoints[i];
        Point p2 = hullPoints[(i+1) % hullPoints.size()];
        Point p3 = hullPoints[(i+2) % hullPoints.size()];

        double angle = atan2(p3.y - p2.y, p3.x - p2.x) - atan2(p1.y - p2.y, p1.x - p2.x);
        angle = angle * 180 / CV_PI;
        angle = abs(angle - 180) < abs(angle) ? abs(angle - 180) : abs(angle);
        angles.push_back(angle);
    }

    // Count the number of fingers
    int numFingers = 0;
    for (int i = 0; i < angles.size(); i++) {
        if (angles[i] > 120) {
            numFingers++;
        }
    }

    std::string text = "Top point: (" + std::to_string(topX) + ", " + std::to_string(topY) + "), Fingers: " + std::to_string(numFingers);

    // Print the text onto the frame
    putText(*frame, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);
    
    drawContours(*frame, std::vector<std::vector<Point>>{hullPoints}, -1, Scalar(0, 255, 0), 2);

    return topPoint;

    
}



