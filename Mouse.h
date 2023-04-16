#ifndef MOUSE_H
#define MOUSE_H

#include<X11/Xlib.h>
#include <X11/extensions/XTest.h>


class Mouse {
public:
    
    Mouse();
    void setCursor(int x, int y);
    void click(int button, bool state);
};




#endif /* MOUSE_H */


