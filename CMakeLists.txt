cmake_minimum_required(VERSION 2.8)
project( WaveGuide )

find_package( OpenCV REQUIRED )
find_package( X11 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${X11_INCLUDE_DIR} ${X11_XTest_INCLUDE_PATH} )

add_subdirectory(tests)

add_executable(waveguide src/main.cpp src/Mouse.cpp src/Mouse.h src/Detect_hands.cpp src/Detect_hands.h src/Camera.cpp src/Camera.h src/Finger_counter.h src/Finger_counter.cpp)

target_link_libraries(waveguide ${OpenCV_LIBS} ${X11_LIBRARIES} ${X11_XTest_LIB} pthread)
