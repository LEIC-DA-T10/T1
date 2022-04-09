cmake_minimum_required(VERSION 3.16)
project(DA_T1)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})


add_executable(main src/main.cpp src/dataIO.cpp src/dataIO.h src/dataStructs.h src/applicationController.cpp src/applicationController.h)
target_link_libraries(main gtest_main)

