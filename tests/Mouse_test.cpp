#include <gtest/gtest.h>
#include "../src/Mouse.h"
#include <X11/Xlib.h>

// Test the click function
TEST(MouseTest, TestClick) {
    Mouse mouse;
    // Click the left button down
    mouse.click(1, true);
    // Click the left button up
    mouse.click(1, false);
    // Test that the function didn't throw any exceptions
    SUCCEED();
}

// Test the setCursor function and get the cursor position
TEST(MouseTest, TestSetCursor) {
    Mouse mouse;
    Display* display = XOpenDisplay(nullptr);
    Window rootWindow = DefaultRootWindow(display);
    int rootX, rootY, winX, winY;
    unsigned int mask;
    XQueryPointer(display, rootWindow, &rootWindow, &rootWindow, &rootX, &rootY, &winX, &winY, &mask);
    // Move the cursor to (100, 100)
    mouse.setCursor(100, 100);
    // Test that the function didn't throw any exceptions
    SUCCEED();
    // Get the cursor position and test that it was set correctly
    XQueryPointer(display, rootWindow, &rootWindow, &rootWindow, &rootX, &rootY, &winX, &winY, &mask);
    // Multipled by 3 for scaling
    EXPECT_EQ(rootX, 100 * 3);
    EXPECT_EQ(rootY, 100 * 3);
    XCloseDisplay(display);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
