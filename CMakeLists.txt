# Test application for different sort algorhythms.
# Copyright (C) 2026  Vladyslav Tupikin
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.22.1)
project(DK_SORT_APP
        LANGUAGES C CXX
        VERSION 0.1
        DESCRIPTION "Test application for different sort algorhythms."
        HOMEPAGE_URL "https://github.com/VladyslavTupikin/dk_sort_app")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)

    message(STATUS "Building for WIN32 system")

    if (NOT "${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
        message(FATAL_ERROR "For Windows, project should be compiled via Microsoft VisualStudio Compiler (MSVC)")
    endif()

elseif(UNIX)

    message(STATUS "Building for UNIX system")

    include(CheckIncludeFile)

    CHECK_INCLUDE_FILE("sys/cdefs.h" FOUND_CDEFS "-m32")
    if(NOT FOUND_CDEFS)
        message(FATAL_ERROR "Can't find the 32bit version of sys/cdefs.h - did you install g++-multilib?")
    endif()

else()
    message(FATAL_ERROR "Unknown Operating System. Windows or Linux suppoted")
endif()

add_subdirectory(src)
