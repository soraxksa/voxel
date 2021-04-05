cmake_minimum_required(VERSION 3.9.1)

project(opengl_test_project)     

#find_package( OpenGL REQUIRED )
#include_directories( ${OPENGL_INCLUDE_DIRS} )

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/glfw)

include_directories(include)

file(GLOB SRC "src/*.c")

add_executable(opengl ${SRC})

target_link_libraries(opengl glfw)




#if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
#	add_definitions(-DCMAKETEST=1)
#	add_definitions(-DHOST_SYS="${CMAKE_SYSTEM_NAME}")
#endif()

#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

#add_library(mymath SHARED lib/math/mymath.c)

#target_link_libraries(opengl mymath)
