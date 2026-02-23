# 0.) Create Source and CMakeFileLists.txt
# 1.) mkdir build
# 2.) cd build
# 3.) cmake ..  # This will generate the Makefile
# 4.) cmake --build .   
# 5.) ./Excecutable

cmake_minimum_required(VERSION 3.5)

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

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(FetchContent)

FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.12.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG 12.1.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.17.0
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts
    GIT_TAG v3.3.1
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(cxxopts)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v2.13.9
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Catch2)

add_git_submodule(external/json)

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src)
if (COMPILE_EXECUTABLE)
    add_subdirectory(app)
else()
    message("W/o exe. compiling")
endif()
