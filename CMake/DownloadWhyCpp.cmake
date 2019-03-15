cmake_minimum_required(VERSION 2.8.2)

project(whycpp-download NONE)

include(ExternalProject)
ExternalProject_Add(whycpp
        URL               https://github.com/senior-sigan/WHY_CPP/archive/v1.8.tar.gz
        URL_MD5           "f196d8ef255a2c190b4682cae6ea0edb"
        SOURCE_DIR        "${CMAKE_CURRENT_BINARY_DIR}/whycpp-src"
        BINARY_DIR        "${CMAKE_CURRENT_BINARY_DIR}/whycpp-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )