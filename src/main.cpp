#include <iostream>
#include <thread>
#include "Detect_hands.h"
#include "Camera.h"

using namespace std;
using namespace cv;

HandDetector handDetector;
Camera camera;

Mat frame, binary, background;
void captureFrames() {
    Mat frame;
    while (true) {
        camera.captureFrame(frame);
        handDetector.detectHands(&frame, &binary);
        char key = waitKey(10);
        if (key == 27) {
            break;
        }
    }
}

int main(int argc, char** argv) {
    camera.setResolution(640, 360);
    camera.captureBackground(background);
    handDetector.setBackground(background);

    thread cameraThread(captureFrames);

    while (true) {
        Mat frame;
        camera.captureFrame(frame);
        imshow("WaveGuide", frame);

        char key = waitKey(10);
        if (key == 27) {
            break;
        }
    }
    
    cameraThread.join();
    destroyAllWindows();
    
    return 0;
}
