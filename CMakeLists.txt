# 0.) Create Source and CMakeFileLists.txt
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..  # This will generate the Makefile
# 4.) cmake --build .   
# 5.) ./Excecutable

cmake_minimum_required(VERSION 3.22)

project(
    CMakeTests
    VERSION 1.0.0
    LANGUAGES C CXX
)

add_executable(Excecutable main.cpp)