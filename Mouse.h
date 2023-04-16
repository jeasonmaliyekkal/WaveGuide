#ifndef MOUSE_H
#define MOUSE_H


#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

class Mouse {
public:
    Mouse();
    void click(int button, bool state);
    void setCursor(int x, int y);
    ~Mouse();
};

#endif
