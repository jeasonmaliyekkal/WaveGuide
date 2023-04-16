#ifndef MOUSE_H
#define MOUSE_H

class Mouse {
public:
    Mouse();
    void click(int button, bool state);
    void setCursor(int x, int y);
    ~Mouse();
};

#endif
