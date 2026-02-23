set(EXE_SOURCES
    main.cpp)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE 
    ${LIBRARY_NAME}
    nlohmann_json)
target_include_directories(${EXECUTABLE_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/inc/bits
)