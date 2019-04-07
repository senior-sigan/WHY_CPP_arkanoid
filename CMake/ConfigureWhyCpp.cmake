configure_file(${CMAKE_DIR}/DownloadWhyCpp.cmake whycpp-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/whycpp-download )
if(result)
    message(FATAL_ERROR "CMake step for whycpp failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/whycpp-download )
if(result)
    message(FATAL_ERROR "Build step for whycpp failed: ${result}")
endif()

add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/whycpp-src/whycpp
        ${CMAKE_CURRENT_BINARY_DIR}/whycpp-build
        EXCLUDE_FROM_ALL)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/whycpp-src/whycpp/include)