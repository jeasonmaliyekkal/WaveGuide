#include <iostream>
#include "Detect_hands.h"
#include "Camera.h"

using namespace std;
using namespace cv;

HandDetector handDetector;
Camera camera;

int main(int argc, char** argv) {
    //VideoCapture cap(0);
    Mat frame, binary, background;
    camera.setResolution(640, 360);
    camera.captureFrame(frame);
    camera.captureBackground(background);
    handDetector.setBackground(background);

    while (true) {
        camera.captureFrame(frame);
    
        // Detect hands in the current frame
        handDetector.detectHands(&frame, &binary);

        // Wait for 10 milliseconds for a key press
        int key = waitKey(10);
        
        // If the 'q' key is pressed, exit the loop
        if (key == '27') {
            break;
        }
    }
    
    // Release the video capture and destroy all windows
    
    destroyAllWindows();
    
    return 0;
}
