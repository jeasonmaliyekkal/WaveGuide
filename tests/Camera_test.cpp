#include <gtest/gtest.h>
#include "../src/Camera.h"

// Fixture class for the Camera tests
class CameraTest : public ::testing::Test {
protected:
    Camera camera;
    cv::Mat testFrame;
    cv::Mat testBackground;

    void SetUp() override {
        // Set up the Camera and capture a test frame
        camera.setResolution(640, 480);
        camera.captureFrame(testFrame);
    }
};

// Test the setResolution function
TEST_F(CameraTest, TestSetResolution) {
    camera.setResolution(1280, 720);
    camera.captureFrame(testFrame);

    EXPECT_EQ(testFrame.cols, 1280);
    EXPECT_EQ(testFrame.rows, 720);
}

// Test the captureFrame function
TEST_F(CameraTest, TestCaptureFrame) {
    cv::Mat frame1, frame2;
    camera.captureFrame(frame1);
    camera.captureFrame(frame2);

    EXPECT_FALSE(frame1.empty());
    EXPECT_FALSE(frame2.empty());
    EXPECT_NE(frame1.data, frame2.data); // Make sure different frames are captured
}

// Test that the camera is opened correctly
TEST_F(CameraTest, TestCameraOpen) {
    EXPECT_TRUE(camera.cap.isOpened());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
