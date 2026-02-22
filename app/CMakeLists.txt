add_executable(Excecutable main.cpp)
target_link_libraries(Excecutable PRIVATE Library)
target_include_directories(Excecutable
    PRIVATE
        ${CMAKE_SOURCE_DIR}/inc/bits,
        ${CMAKE_SOURCE_DIR}/inc/my_lib
)