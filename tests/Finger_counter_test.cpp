#include <gtest/gtest.h>
#include "../src/Finger_counter.h"

// Test the findPointsDistance function
TEST(FingerCounterTest, TestFindPointsDistance) {
    FingerCounter fingerCounter;
    Point a(0, 0);
    Point b(3, 4);
    double distance = fingerCounter.findPointsDistance(a, b);
    EXPECT_EQ(distance, 5.0);
}

// Test the findAngle function
TEST(FingerCounterTest, TestFindAngle) {
    FingerCounter fingerCounter;
    Point a(0, 0);
    Point b(3, 0);
    Point c(0, 4);
    double angle = fingerCounter.findAngle(a, b, c);
    EXPECT_NEAR(angle, 1.570796, 0.001);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
