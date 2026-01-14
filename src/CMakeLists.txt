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
#set(LIBDKDNS_PC dkdns.pc)
#set(LIBDKDNS_PC_TMPLT dkdns.pc.in)
#set(CMAKE_C_STANDARD 11)

set(DK_SORT_SRC
    main.cpp
    dk_sort_bubble_common.cpp
    dk_sort_bubble_quicker_asm.cpp
    dk_sort_bubble_quicker.cpp
    dk_sort_perfomance.cpp
    dk_sort_bubble_optimized.cpp
    dk_sort_bubble_optimized_asm.cpp
    )

set(DK_SORT_INCLUDE
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_common.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_quicker_asm.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_quicker.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_iface.hpp
    ${CMAKE_SOURCE_DIR}/dk_sort_perfomance.hpp
    ${CMAKE_SOURCE_DIR}/dk_sort_bubble_optimized.hpp
    ${CMAKE_SOURCE_DIR}/dk_sort_bubble_optimized_asm.hpp
    )

add_executable(${DK_SORT} ${DK_SORT_SRC})

target_include_directories(${DK_SORT} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${DK_SORT} PROPERTIES
    OUTPUT_NAME "${DK_SORT}"
)

if(WIN32)
    #set(CPP_FLAGS ${CPP_FLAGS} /EHsc /std:c++20 /DENABLE_PRINT_ARRAY)
    set(CPP_FLAGS ${CPP_FLAGS} /EHsc /std:c++20 /O2)
elseif(UNIX)
    #set(CPP_FLAGS ${CPP_FLAGS} "-DENABLE_PRINT_ARRAY" "-masm=intel")
    set(CPP_FLAGS ${CPP_FLAGS} "-std=c++20" "-O3" "-masm=intel")
else()
    # Actions for other platforms
    message(FATAL_ERROR "Unsupported platform")
endif()

target_compile_options(${DK_SORT} PRIVATE ${CPP_FLAGS})
