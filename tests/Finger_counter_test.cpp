#include "src/Finger_counter.h"
#include "gtest/gtest.h"


TEST(FingerCounterTest, FindPointsDistanceTest) {
    FingerCounter fc;
    Point a(1, 1);
    Point b(4, 5);
    double distance = fc.findPointsDistance(a, b);
    EXPECT_DOUBLE_EQ(distance, 5.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
