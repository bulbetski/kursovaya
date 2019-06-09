cmake_minimum_required(VERSION 3.13)
project(kursovaya)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursovaya main.cpp Complex.cpp Complex.h display.cpp display.h Preload.cpp Preload.h)
target_link_libraries(kursovaya -lOpenGL32 -lfreeGLUT)