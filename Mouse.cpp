#include "Mouse.h"
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

Mouse::Mouse() {
    // XInitThreads();
}

void Mouse::click(int button, bool state) {
    Display *display = XOpenDisplay(nullptr);
    XTestFakeButtonEvent(display, button, state, CurrentTime);
    XCloseDisplay(display);
}

void Mouse::setCursor(int x, int y) {
    Display *display = XOpenDisplay(nullptr);
    XWarpPointer(display, None, None, 0, 0, 0, 0, x, y);
    XCloseDisplay(display);
}

Mouse::~Mouse() {}
