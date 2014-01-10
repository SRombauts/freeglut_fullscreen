# Copyright (c) 2014 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 

cmake_minimum_required(VERSION 2.6)
project(freeglut_fullscreen)


## Core source code ##

# adding a new file require explicittly modifing the CMakeLists.txt
# so that CMake knows that it should rebuild the project (it is best practice)

# add sources for the executable :
add_executable(freeglut_fullscreen
 src/Fullscreen.cpp
)


## Libraries ##

# add the subdirectory of the freeglut static library (but disable any other build)
set(FREEGLUT_BUILD_SHARED_LIBS OFF CACHE BOOL "Build FreeGLUT shared library.")
set(FREEGLUT_BUILD_DEMOS OFF CACHE BOOL       "Build FreeGLUT demos.")
add_definitions(-DFREEGLUT_STATIC)
add_subdirectory(freeglut/freeglut/freeglut)
include_directories("${PROJECT_SOURCE_DIR}/freeglut/freeglut/freeglut/include")


## Linking ##

# link the executable with all required libraries
target_link_libraries(freeglut_fullscreen freeglut_static)


