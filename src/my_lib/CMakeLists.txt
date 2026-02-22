add_library(Library STATIC my_lib.cpp)
target_include_directories(Library
    PUBLIC
        ${CMAKE_SOURCE_DIR}/inc/bits,
        ${CMAKE_SOURCE_DIR}/inc/my_lib
)