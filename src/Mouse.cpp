#include "Mouse.h"

Mouse::Mouse() {
    // XInitThreads();
}

void Mouse::click(int button, bool state){
    Display* dpy = XOpenDisplay(NULL);
    // button = left mouse button and button = 2 for middle button and button = 3 for right button.
    // state = True implies button press, state = false implies button release
    XTestFakeButtonEvent(dpy, button, state, 0); // Press or Release Mouse Button
    XFlush(dpy);
    XCloseDisplay(dpy);
}

void Mouse::setCursor(int x, int y){
  Display *dpy = XOpenDisplay(NULL); // open the default display
  Window root = DefaultRootWindow(dpy); // get the root window
  XWarpPointer(dpy, None, root, 0, 0, 0, 0, x*3, y*3); // multiplying by 3 to cover whole screen move the pointer
  XCloseDisplay(dpy);
}

Mouse::~Mouse() {}
