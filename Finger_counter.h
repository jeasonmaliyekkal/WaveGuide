#ifndef FINGER_COUNTER_H
#define FINGER_COUNTER_H

#include "Detect_hands.h"

class FingerCounter {
public:
    FingerCounter();
    double findPointsDistance(Point a, Point b);
    double findAngle(Point a, Point b, Point c);
    ~FingerCounter();
};

#endif
