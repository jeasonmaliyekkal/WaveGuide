#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "../src/Finger_counter.h"

using namespace cv;

TEST(FingerCounterTest, TestFindPointsDistance) {
    FingerCounter fc;
    Point a(0, 0);
    Point b(3, 4);
    double expected_distance = 5.0;
    EXPECT_DOUBLE_EQ(fc.findPointsDistance(a, b), expected_distance);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}