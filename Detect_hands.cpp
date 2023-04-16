#include "Detect_hands.h"

HandDetector::HandDetector() {}

void HandDetector::setBackground(cv::Mat bg) {
background = bg.clone();
}

void HandDetector::detectHands(cv::Mat *frame, cv::Mat *bin) {
cv::Mat one, two;
cv::cvtColor(*frame, one, cv::COLOR_BGR2GRAY);
cv::cvtColor(background, two, cv::COLOR_BGR2GRAY);
cv::Mat diff;
cv::absdiff(two, one, diff);

// Convert the difference image to binary
cv::threshold(diff, *bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

std::vector<std::vector<cv::Point>> contours;
std::vector<cv::Vec4i> hierarchy;
cv::findContours(*bin, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

// Find the contour with the largest area
double maxArea = 0;
int maxAreaIdx = -1;
for (int i = 0; i < contours.size(); i++) {
    double area = cv::contourArea(contours[i]);
    if (area > maxArea) {
        maxArea = area;
        maxAreaIdx = i;
    }
}

// Create a convex hull from the largest contour
std::vector<int> hullIndices;
cv::convexHull(contours[maxAreaIdx], hullIndices);

// Draw the convex hull on the original image
cv::drawContours(*frame, std::vector<std::vector<cv::Point>>{contours[maxAreaIdx]}, -1, cv::Scalar(0, 0, 255), 2);

std::vector<cv::Point> hullPoints;
for (int i = 0; i < hullIndices.size(); i++) {
    hullPoints.push_back(contours[maxAreaIdx][hullIndices[i]]);
}

cv::Point topPoint = hullPoints[0];
for (int i = 1; i < hullPoints.size(); i++) {
    if (hullPoints[i].y < topPoint.y) {
        topPoint = hullPoints[i];
    }
}

//mouse.setCursor(topPoint.x, topPoint.y);
//mouse.click(0, true);
}