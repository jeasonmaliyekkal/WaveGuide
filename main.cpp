#include <opencv2/opencv.hpp>
#include<unistd.h>


using namespace cv;

Point detectHands(Mat *frame, Mat *background, Mat *bin);
void click(int button, bool state);
void setCursor(int x, int y);

int main() {
    // Create a VideoCapture object for the default camera
    VideoCapture cap(0);

    //setting resolution
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 360);

    // Check if the camera is opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error opening camera" << std::endl;
        return -1;
    }

    // Create a window to display the video
    namedWindow("WaveGuide", WINDOW_AUTOSIZE);

    Mat background;
    Mat bin;
    bool bg = true;
    while (bg)
    {
       Mat frame;
       cap.read(frame);
       flip(frame, frame, 1);
          if (frame.empty()) {
            std::cerr << "Error capturing frame" << std::endl;
            break;
        }
         if (waitKey(10) == 120) {
            std::cout << "Captured background" << std::endl;
            cap.read(background);
            flip(background, background, 1);
            bg = false;
        }
   
        // Display the frame in the window
        Point org(50, 50); // bottom-left corner of the text
        int fontFace = FONT_HERSHEY_SIMPLEX; // font type
        double fontScale = 1.0; // font scale factor
        Scalar color(0, 255, 0); // text color (green)
        int thickness = 2; // text thickness

        putText(frame," Press X to Capture Background", org , fontFace, fontScale, color, thickness);
        imshow("WaveGuide", frame);

    }
    
    while (true) {
        // Capture a frame from the camera
        
        Mat frame;
         
        cap.read(frame);
        flip(frame, frame, 1);
        // Check if the frame was successfully captured
        if (frame.empty()) {
            std::cerr << "Error capturing frame" << std::endl;
            break;
        }

        //calling detectframes 
        Point cursor = detectHands(&frame,&background, &bin);
        // Display the frame in the window
        setCursor(cursor.x*3, cursor.y*3);
        imshow("background", background);
        moveWindow("background", 700,62);
        imshow("Binary Mask", bin);
        moveWindow("Mask", 42,462);
        imshow("WaveGuide", frame);

        // Wait for 10 milliseconds for a key event
        if (waitKey(10) == 27) {
            std::cout << "Esc key is pressed by user" << std::endl;
            break;
        }
    }

    // Release the VideoCapture object and close the window
    cap.release();
    destroyAllWindows();

    return 0;
}
