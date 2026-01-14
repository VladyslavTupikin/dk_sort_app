# Simple C library for work with DNS messages - libdkdns

## Overview

Application designed to practice C++ and test some possible improvements for different sorting algorhytms.

## Building

Application written on C++ 20 with CMake build system.

### Windows with MS Visual Studio Developer Command Prompt
1. Prepare 32-bit build environment. MS Visual Studio for x64 does not support inline assembly.
    ```
    cmake -B ./build -A Win32
    ```
2. Build dksort_app executable:
    ```
    cmake --build build --config Release
    ```

### Linux with GCC (g++) and 32bit multilib support
1. Prepare build environment. CPP_FLAGS already contains -m32 flag for building 32bit app.
    ```
    cmake -B build --toolchain toolchains/i386.cmake
    ```
2. Build dksort_app executable:
    ```
    cmake --build build --config Release
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
