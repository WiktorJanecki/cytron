cmake_minimum_required(VERSION 3.12)

project(cytron)

set(EXECUTABLE_NAME "cytron")

file(GLOB_RECURSE CYTRON_SRC
    ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(
    ${CMAKE_SOURCE_DIR}/include)
include_directories(
    ${CMAKE_SOURCE_DIR}/lib)


find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(${EXECUTABLE_NAME} ${CYTRON_SRC})
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio)

