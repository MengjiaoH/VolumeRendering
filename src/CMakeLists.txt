#
# initialize project
get_filename_component(PID ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(TOLOWER ${PID} PID)
#
# install dlls or shader
file(GLOB SHADERS "shaders/*.glsl")
set(COPYLIST ${SHADERS})
if(EXECUTABLE_OUTPUT_PATH)
  DeployRepo("${COPYLIST}" "${EXECUTABLE_OUTPUT_PATH}")
else()
  DeployRepo("${COPYLIST}" "${CMAKE_BINARY_DIR}")
endif()

#
# include sources
file(GLOB MAIN "main.cpp")
file(GLOB CAMERACXX "camera/*.cpp")
file(GLOB CAMERAHXX "camera/*.h")
file(GLOB CXX  "*.cpp")
file(GLOB HXX  "*.h")
file(GLOB HPP  "*.hpp")
foreach(f ${MAIN})
  list(REMOVE_ITEM CXX ${f})
endforeach()

#
# add library
add_library(common_${PID} ${CXX} ${HXX} ${HPP} ${CAMERACXX} ${CAMERAHXX} datastruct.h)
target_link_libraries(common_${PID} ${COMMON_LIBS})
set_target_properties(common_${PID}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  CXX_STANDARD 11)
#
# add executable
add_executable(RayCastingVR ${MAIN})
target_link_libraries(RayCastingVR common_${PID} ${COMMON_LIBS})
set_target_properties(RayCastingVR
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
  CXX_STANDARD 11)

