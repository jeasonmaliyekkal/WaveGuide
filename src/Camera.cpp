#include "Camera.h"

Camera::Camera() {
    cap.open(0);
    if (!cap.isOpened()) {
        std::cerr << "Error: could not open camera or video file" << std::endl;
    }
}

void Camera::setResolution(int width, int height) {
    cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);
}

void Camera::captureFrame(cv::Mat& frame) {
    cap.read(frame);
    cv::flip(frame, frame, 1);
}

void Camera::captureBackground(cv::Mat& background) {
    bool bg = true;
    while (bg)
    {
        cv::Mat frame;
        captureFrame(frame);

        if (frame.empty()) {
            std::cerr << "Error capturing frame" << std::endl;
            break;
        }

        if (cv::waitKey(10) == 120) {
            std::cout << "Captured background" << std::endl;
            frame.copyTo(background);

            bg = false;
        }

        // Display the frame in the window
        cv::Point org(50, 50); // bottom-left corner of the text
        int fontFace = cv::FONT_HERSHEY_SIMPLEX; // font type
        double fontScale = 1.0; // font scale factor
        cv::Scalar color(0, 255, 0); // text color (green)
        int thickness = 2; // text thickness

        cv::putText(frame," Press X to Capture Background", org , fontFace, fontScale, color, thickness);
        cv::imshow("WaveGuide", frame);
    }
}

Camera::~Camera() {
    cap.release();
}
