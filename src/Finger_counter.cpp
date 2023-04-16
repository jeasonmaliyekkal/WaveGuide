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

int FingerCounter::fingerCount(std::vector<std::vector<Point>> contours, int maxAreaIdx, std::vector<int> hullIndices, Mat* frame){
    // Find the convexity defects in the hull
    std::vector<Vec4i> defects;
    convexityDefects(contours[maxAreaIdx], hullIndices, defects);
    Point start_point;
    Point end_point;
    Point far_point;

    int count = 0;

    // Draw the defects on the original image
    for (int i = 0; i < defects.size(); i++) {
        start_point = contours[maxAreaIdx][defects[i].val[0]];
        end_point = contours[maxAreaIdx][defects[i].val[1]];
        far_point = contours[maxAreaIdx][defects[i].val[2]];
        double angle = findAngle(far_point,start_point,end_point);

        if(defects[i].val[3] > 1000 and angle <=CV_PI/2.5){
            count = count+1;
            circle(*frame, end_point, 8, -1);
        }
    }
    return count;
}

FingerCounter::~FingerCounter() {}
