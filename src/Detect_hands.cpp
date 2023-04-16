#include "Detect_hands.h"
#include "Finger_counter.h"

HandDetector::HandDetector() {}

Mouse mouse;
FingerCounter fingerCounter;

void HandDetector::setBackground(Mat bg) {
    background = bg.clone();
}

void HandDetector::detectHands(Mat *frame, Mat *bin) {
    Mat one, two;
    cvtColor(*frame, one, COLOR_BGR2GRAY);
    cvtColor(background, two, COLOR_BGR2GRAY);
    Mat diff;
    absdiff(two, one, diff);

    // Convert the difference image to binary
    threshold(diff, *bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(*bin, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // Find the contour with the largest area
    double maxArea = 0;
    int maxAreaIdx = -1;
    for (int i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = area;
            maxAreaIdx = i;
        }
    }

    // Create a convex hull from the largest contour
    std::vector<int> hullIndices;
    convexHull(contours[maxAreaIdx], hullIndices);

    // Draw the contour on the original image
    drawContours(*frame, std::vector<std::vector<Point>>{contours[maxAreaIdx]}, -1, Scalar(0, 0, 255), 2);



    std::vector<Point> hullPoints;
    for (int i = 0; i < hullIndices.size(); i++) {
        hullPoints.push_back(contours[maxAreaIdx][hullIndices[i]]);
    }

    Point topPoint = hullPoints[0];
    for (int i = 1; i < hullPoints.size(); i++) {
        if (hullPoints[i].y < topPoint.y) {
            topPoint = hullPoints[i];
        }
    }
    // Draw the convex hull on the original image
    drawContours(*frame, std::vector<std::vector<Point>>{hullPoints}, -1, Scalar(0, 255, 0), 2);
    int verts = hullPoints.size();

    // The top point's x and y coordinates can be accessed as follows:
    int topX = topPoint.x;
    int topY = topPoint.y;

    mouse.setCursor(topPoint.x, topPoint.y);
    mouse.click(0, true);

    int count = fingerCounter.fingerCount(contours, maxAreaIdx, hullIndices, frame);

    std::string text = "Top point: (" + std::to_string(topX) + ", " + std::to_string(topY) + ") "+ std::to_string(count);
    // Print the text onto the frame
    putText(*frame, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 2);
    
    imshow("Current Frame", *frame);
    imshow("Binary Image", *bin);

    if (count >= 4){
        mouse.click(1, false);
        mouse.setCursor(topX, topY);
    }
    else{
        mouse.click(1, true);
        mouse.setCursor(topX, topY);
    }
}