cmake_minimum_required(VERSION 3.0)

project(nolog)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

if(UNIX)
	set(CMAKE_CXX_FLAGS "-m32 -fvisibility=hidden")
	set(CMAKE_C_FLAGS "-m32 -fvisibility=hidden")
	set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
endif()

# removes the sprintf warnings from plugin-natives
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/test/plugins)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(SUBHOOK_STATIC ON CACHE BOOL "Build as a static library")
set(SUBHOOK_NO_INSTALL ON CACHE BOOL "Do not install any files")
set(SUBHOOK_NO_TESTS ON CACHE BOOL "Exclude tests from build")

add_subdirectory(lib/subhook)
add_subdirectory(src)
