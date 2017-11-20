cmake_minimum_required(VERSION 3.5)
project(RayCastingVolumeRendering)

set(CMAKE_CXX_STANDARD 11)

include(cmake/common.cmake)

# load projects
#set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
#add_subdirectory(${SRC_DIR})

add_subdirectory(src)

set(COPYLIST ${COMMON_DLLS})
if(EXECUTABLE_OUTPUT_PATH)
    DeployRepo("${COPYLIST}" "${EXECUTABLE_OUTPUT_PATH}")
else()
    DeployRepo("${COPYLIST}" "${CMAKE_BINARY_DIR}")
endif()
