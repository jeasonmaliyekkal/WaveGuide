cmake_minimum_required(VERSION 2.8)
project(WaveGuideTests)

find_package(OpenCV REQUIRED)
find_package(X11 REQUIRED)
find_package(GTest REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${X11_INCLUDE_DIR} ${X11_XTest_INCLUDE_PATH})
include_directories(${GTEST_INCLUDE_DIRS})

set(TEST_FILES
    Finger_counter_test.cpp
    Mouse_test.cpp
    Camera_test.cpp
)

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE} ../src/Finger_counter.cpp ../src/Finger_counter.h ../src/Mouse.cpp ../src/Mouse.h ../src/Detect_hands.cpp ../src/Detect_hands.h ../src/Camera.cpp ../src/Camera.h)
    target_link_libraries(${TEST_NAME} ${OpenCV_LIBS} ${X11_LIBRARIES} ${X11_XTest_LIB} ${GTEST_LIBRARIES} pthread)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()
