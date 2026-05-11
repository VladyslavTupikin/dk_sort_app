# Test application for different sort algorithms.

## Overview

Application designed to practice C++ and test some possible improvements for different sorting algorhytms.

## Building

Application written on C++ 20 with CMake build system.

### Prepare environment

1. Prepare Windows environment

   Download Microsoft Visual Studio Community, and during installation process enable C and C++ checkboxes.
   Developer command prompt will be installed as part of the MSVC package.

2. Prepare Linux environment

   Application has a build-time dependcy on the next packages:

   ```
   gcc
   g++
   gcc-multilib
   g++-multilib
   cmake
   build-essentials
   ```

### Windows with MS Visual Studio Developer Command Prompt

1. Prepare 32-bit build environment. MS Visual Studio for x64 does not support inline assembly.
   1. Without printing an array
      ```
      cmake -B ./build -A Win32 -D SET_ARRAY_SIZE:INT=20
      ```
   2. Print the array itself
      ```
      cmake -B ./build -A Win32 -DENABLE_PRINT_ARRAY:BOOL=1 -D SET_ARRAY_SIZE:INT=20
      ```
2. Build dksort_app executable:
   1. Build release app
      ```
      cmake --build build --config Release
      ```
   2. Build debug app
      ```
      cmake --build build --config Debug
      ```

### Linux with GCC (g++) and 32bit multilib support

1. Prepare build environment. Compilation flags already contains -m32 flag for building 32bit app.
   Supprted build types are Release and Debug. Release produces optimized and stripped tiny executable binary.
   Debug produces "fat" executable binary without compiler optimization and with all necessary debug information for GDB.
   1. Without printing an array
      ```
      cmake -B build --toolchain toolchains/i386.cmake -DSET_ARRAY_SIZE:INT=20 -DCMAKE_BUILD_TYPE=Release
      ```
   2. Print the array itself
      ```
      cmake -B build --toolchain toolchains/i386.cmake -DENABLE_PRINT_ARRAY:BOOL=1 -DSET_ARRAY_SIZE:INT=20 -DCMAKE_BUILD_TYPE=Release
      ```
2. Build dksort_app executable:
   ```
   cmake --build build
   ```

## Installation

1. Install library on your host machine (Optional):

   ```
   TODO
   ```

2. Installed files can be removed from the host system:
   ```
   TODO
   ```

## License

Current project developed under GNU General Public License v3.0. Text of the licence can be found in LICENSE file of current repository or on the official web site: https://www.gnu.org/licenses/gpl-3.0.html
