#include "Finger_counter.h"

FingerCounter::FingerCounter() {}

double FingerCounter::findPointsDistance(Point a, Point b) {
    Point difference = a - b;
    return sqrt(difference.ddot(difference));
}

double FingerCounter::findAngle(Point a, Point b, Point c) {
    double ab = findPointsDistance(c, b);
    double bc = findPointsDistance(a, b);
    double ca = findPointsDistance(a, c);
    return acos((bc * bc + ca * ca - ab * ab) / (2 * bc * ca));
}

FingerCounter::~FingerCounter() {}
