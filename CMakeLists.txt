#######################################################################
# Copyright (C) 2025 Savelii Pototskii (savalione.com)
# 
# Author: Savelii Pototskii <savelii.pototskii@gmail.com>
# 
# This file is part of jenkins-cpp-example.
# 
# jenkins-cpp-example is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3
# of the License, or (at your option) any later version.
# 
# jenkins-cpp-example is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with jenkins-cpp-example. If not, see <https://www.gnu.org/licenses/>.
#######################################################################
cmake_minimum_required (VERSION 3.16)

project(jenkins-cpp-example
    VERSION "1.0.0"
    DESCRIPTION "jenkins-cpp-example is an example C++ project demonstrating Jenkins CI/CD integration, primarily by allowing explicit control over its exit status for testing purposes."
    HOMEPAGE_URL "https://github.com/SavaLione/jenkins-cpp-example"
    LANGUAGES C CXX
)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build to release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g")
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -DNDEBUG")
else()
    message(STATUS "Unknown build type: " ${CMAKE_BUILD_TYPE})
endif()

# CMake configure
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/config.h)

# Source files
set(JCE_SRC
    src/jenkins-cpp-example.cpp
    src/xgetopt/xgetopt.c
)

# Executable
add_executable(${PROJECT_NAME} ${JCE_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)
