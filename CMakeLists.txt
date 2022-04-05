cmake_minimum_required(VERSION 3.16)
project(DA_T1)

add_executable(DA_T1 src/main.cpp)


# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

file(GLOB TP1_FILES CONFIGURE_DEPENDS "TP1/*.cpp")

add_executable(TP1 src/main.cpp ${TP1_FILES})
#...

target_link_libraries(TP1 gtest_main gmock_main)
#...

