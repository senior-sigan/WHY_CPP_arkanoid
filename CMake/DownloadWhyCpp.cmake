cmake_minimum_required(VERSION 2.8.2)

project(whycpp-download NONE)

include(ExternalProject)
ExternalProject_Add(whycpp
#        URL               https://github.com/senior-sigan/WHY_CPP/archive/v1.13.tar.gz
#        URL_MD5           "f631028519be8c60b6e5f4138d5185e0"
        GIT_REPOSITORY https://github.com/senior-sigan/WHY_CPP.git
        GIT_SHALLOW ON
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/whycpp-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/whycpp-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )