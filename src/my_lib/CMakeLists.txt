set(LIBRARY_SOURCES
    my_lib.cpp)
set(LIBRARY_HEADERS
    my_lib.h)

add_library(${LIBRARY_NAME} STATIC 
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS}
)
target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/inc/bits
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/configured_files/include
)