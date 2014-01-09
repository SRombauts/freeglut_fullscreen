# Copyright (c) 2014 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT) 

cmake_minimum_required(VERSION 2.6)
project(fullscreen)


## Core source code ##

# All includes are relative to the "src" directory 
include_directories("${PROJECT_SOURCE_DIR}/src")

# adding a new file require explicittly modifing the CMakeLists.txt
# so that CMake knows that it should rebuild the project (it is best practice)

# add sources for the executable :
add_executable(fullscreen
 src/Fullscreen.cpp
)

## Linking ##

# link the executable with all required libraries
target_link_libraries(fullscreen glut)


