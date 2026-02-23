add_library(${LIBRARY_NAME} STATIC my_lib.cpp)
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_SOURCE_DIR}/inc/bits
        ${CMAKE_SOURCE_DIR}/inc/my_lib
)