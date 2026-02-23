function(add_git_submodule dir)
    find_package(Git REQUIRED)  # Git must be available

    if (NOT EXISTS ${dir}/CMakeLists.txt)
        execute_process(COMMAND ${GIT_EXECUTABLE}   # find_package(Git) sets GIT_EXECUTABLE
            submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
    endif()

    if (EXISTS ${dir}/CMakeLists.txt)   # Only add subdirectory if Git submodule is a CMake project
        message("Adding: ${dir}/CMakeLists.txt")
        add_subdirectory(${dir})
    else()
        message("Could not add: ${dir}/CMakeLists.txt")
    endif()    
endfunction(add_git_submodule)