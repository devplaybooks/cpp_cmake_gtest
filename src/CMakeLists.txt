set(SRC_LIB_NAME src)
add_library(${SRC_LIB_NAME})
target_sources(${SRC_LIB_NAME} PRIVATE example.cpp)
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    target_compile_options(${SRC_LIB_NAME} PRIVATE --coverage)
    target_link_options(${SRC_LIB_NAME} PUBLIC --coverage)
    add_custom_command(TARGET ${SRC_LIB_NAME} PRE_BUILD COMMAND
            find ${CMAKE_BINARY_DIR} -type f
            -name '*.gcda' -exec rm {} +)
endif()
