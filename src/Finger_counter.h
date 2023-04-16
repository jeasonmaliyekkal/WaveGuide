#ifndef FINGER_COUNTER_H
#define FINGER_COUNTER_H

#include "Detect_hands.h"

class FingerCounter {
public:
    FingerCounter();
    double findPointsDistance(Point a, Point b);
    double findAngle(Point a, Point b, Point c);
    int fingerCount(std::vector<std::vector<Point>> contours, int maxAreaIdx, std::vector<int> hullIndices, Mat* frame);
    ~FingerCounter();
};

#endif
