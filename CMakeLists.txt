cmake_minimum_required(VERSION 3.22)

project(
        cpp_gtest
        VERSION 0.0.1
        DESCRIPTION "C++ CMake GTest Template Project"
        LANGUAGES C CXX)

# GoogleTest requires at least C++11
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#######
# GCov
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage ${PROJECT_TEST_NAME} coverage)
endif()
if(CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(${PROJECT_TEST_NAME} gcov)
endif()
#
########

include(FetchContent)

#-------------------
# CMake Modules
#-------------------
# Source: https://github.com/bilke/cmake-modules
# https://stackoverflow.com/questions/13116488/detailed-guide-on-using-gcov-with-cmake-cdash
#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/modules")

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

# uncomment this line to enable coverage measurements using gcov
#set(CMAKE_CXX_FLAGS "--coverage")

enable_testing()
include_directories(${COMMON_INCLUDES})
add_subdirectory(src)
add_subdirectory(test)
