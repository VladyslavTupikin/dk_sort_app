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


set(DK_SORT dksort_app)

set(DK_SORT_SRC
    main.cpp
    test_exec.cpp
    dk_sort_bubble_common.cpp
    dk_sort_bubble_quicker_asm.cpp
    dk_sort_bubble_quicker.cpp
    dk_sort_perfomance.cpp
    dk_sort_bubble_optimized.cpp
    dk_sort_bubble_optimized_asm.cpp
    )

add_executable(${DK_SORT} ${DK_SORT_SRC})

target_include_directories(${DK_SORT} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${DK_SORT} PROPERTIES
    OUTPUT_NAME "${DK_SORT}"
)

if( (NOT EXIST ${SET_ARRAY_SIZE}) OR ("${SET_ARRAY_SIZE}" LESS_EQUAL "0") )
    message(FATAL_ERROR "Array size should be directly specified like -DSET_ARRAY_SIZE=20")
endif()

if(WIN32)

    if(${ENABLE_PRINT_ARRAY})
        set(CPP_FLAGS ${CPP_FLAGS} /EHsc /std:c++20 /O2 /DENABLE_PRINT_ARRAY /DARRAY_SIZE=${SET_ARRAY_SIZE})
    else()
        set(CPP_FLAGS ${CPP_FLAGS} /EHsc /std:c++20 /O2 /DARRAY_SIZE=${SET_ARRAY_SIZE})
    endif()

elseif(UNIX)

    set(CPP_FLAGS ${CPP_FLAGS} "-Wall" "-Werror" "-Wextra" "--pedantic") # Build with strict flags
    set(CPP_FLAGS ${CPP_FLAGS} "-std=c++20" "-masm=intel" "-DARRAY_SIZE=${SET_ARRAY_SIZE}")
    set(CPP_FLAGS ${CPP_FLAGS} "-D_FORTIFY_SOURCE=3") # Enable security check for memory vulnerabilities

    if("${CMAKE_BUILD_TYPE}" STREQUAL "Release")

        set(CPP_FLAGS ${CPP_FLAGS} "-O3") # Enable maximum optimization

        add_custom_command(
            TARGET ${DK_SORT} POST_BUILD
            COMMAND ${CMAKE_STRIP}
            ARGS $<TARGET_FILE:${DK_SORT}>
            COMMENT "Stripping release binary: ${DK_SORT}"
        )
    elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")

        set(CPP_FLAGS ${CPP_FLAGS} "-O0") # Disable optimization
        set(CPP_FLAGS ${CPP_FLAGS} "-g") # Add debug inffo to the binary
    else()
        message(FATAL_ERROR "Unsupported build type.")
    endif()

    if(${ENABLE_PRINT_ARRAY})
        set(CPP_FLAGS ${CPP_FLAGS} "-DENABLE_PRINT_ARRAY")
    endif()

else()
    message(FATAL_ERROR "Unsupported platform")
endif()

target_compile_options(${DK_SORT} PRIVATE ${CPP_FLAGS})
