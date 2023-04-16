#include <iostream>
#include <opencv2/opencv.hpp>
#include "Detect_hands.h"
#include "Camera.h"

using namespace std;
using namespace cv;

HandDetector handDetector;
Camera camera;

int main(int argc, char** argv) {
    //VideoCapture cap(0);
    Mat frame, binary, background;
    camera.captureFrame(frame);
    camera.captureBackground(background);
    handDetector.setBackground(background);

    
    // // Open the default camera or a video file specified by the user
    // if (argc < 2) {
    //     cap.open(0);
    // }
    // else {
    //     cap.open(argv[1]);
    // }
    
    // Check if the camera or video file opened successfully
    // ÷
    
     while (true) {
        camera.captureFrame(frame);
    //     // Capture a new frame
    //     cap.read(frame);
        
    //     // Check if the frame was successfully captured
    //     if (frame.empty()) {
    //         cerr << "Error: could not capture frame" << endl;
    //         break;
    //     }
        
        // Detect hands in the current frame
        handDetector.detectHands(&frame, &binary);
        
        // Display the current frame and binary image

        
        // Wait for 10 milliseconds for a key press
        int key = waitKey(10);
        
        // If the 'q' key is pressed, exit the loop
        if (key == 'q') {
            break;
        }
    }
    
    // Release the video capture and destroy all windows
    
    destroyAllWindows();
    
    return 0;
}
