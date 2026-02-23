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

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(LIBRARY_NAME Library)
set(EXECUTABLE_NAME Executable)

option(COMPILE_EXECUTABLE "Whether to compile the executable" ON)

add_subdirectory(src)
if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("W/o exe. compiling")
endif()
