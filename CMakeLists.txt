cmake_minimum_required(VERSION 3.6)
project(game LANGUAGES CXX) # имя проекта и язык используемый в проекте (c++)

set(CMAKE_CXX_STANDARD 17) # стандарт с++ 2017
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Winit-self -Wswitch-default -Wfloat-equal -Wno-unused-const-variable -Wno-unused-parameter -fPIC -march=native")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3") # включаем оптимизаци компилятора
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # добавляем дебажные символы в бинарный файл для отладки

set(CMAKE_DIR "${PROJECT_SOURCE_DIR}/CMake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_DIR}") # добавляем дополнительные модули CMake

set(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)

include_directories(${PROJECT_HEADERS_DIR})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${WHYCPP_LIBRARIES})

set(SDL2_FROM_SOURCE OFF)
include(ConfigureWhyCpp)
target_link_libraries(${PROJECT_NAME} whycpp)