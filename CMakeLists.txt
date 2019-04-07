cmake_minimum_required(VERSION 3.6)
project(game LANGUAGES CXX) # имя проекта и язык используемый в проекте (c++)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-const-variable -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для отладки

set(CMAKE_DIR "${PROJECT_SOURCE_DIR}/CMake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_DIR}") # добавляем дополнительные модули CMake

if (EMSCRIPTEN)
    add_definitions(-DEMSCRIPTEN)
    add_definitions(-DUSE_WASM)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --bind --memory-init-file 0 -s TOTAL_MEMORY=64*1024*1024 -s SAFE_HEAP=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s USE_SDL=2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 --use-preload-plugins")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    file(COPY html/index.html DESTINATION ${CMAKE_BINARY_DIR})
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -march=native")

    # SHOULD BE MOVED TO THE WHYCPP LIB
    find_package(SDL2 REQUIRED)
    find_package(SDL2_mixer REQUIRED)

endif ()

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(${PROJECT_HEADERS_DIR})

# Should be target include!!!
include_directories(${PROJECT_NAME} ${SDL2_MIXER_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${WHYCPP_LIBRARIES})

set(SDL2_FROM_SOURCE OFF)
include(ConfigureWhyCpp)
target_link_libraries(${PROJECT_NAME} whycpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_MIXER_LIBRARIES})