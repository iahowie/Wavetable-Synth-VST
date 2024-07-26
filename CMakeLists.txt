

cmake_minimum_required(VERSION 3.30)

project(AudioPluginStarter)

set(CMAKE_CXX_STANDARD 23)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
include(cmake/cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE
    GIT_TAG 8.0.0
    VERSION 8.0.0
    SOURCE_DIR ${LIB_DIR}/juce
)  

CPMAddPackage(
    NAME GOOGLETEST
    VERSION 1.15.0
    GITHUB_REPOSITORY google/googletest
    SOURCE_DIR ${LIB_DIR}/googletest 
    OPTIONS
        "INSTALL_GTEST OFF"
        "gtest_force_shared_crt ON"
)

enable_testing()

if (MSVC)
    add_compile_options(/Wall /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(plugin)
add_subdirectory(test)
