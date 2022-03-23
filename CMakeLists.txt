cmake_minimum_required(VERSION 3.0.0)
project(Project5 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src)

configure_file(${PROJECT_SOURCE_DIR}/src/prices.txt ${PROJECT_BINARY_DIR} COPYONLY)
