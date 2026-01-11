# Test application for different sort algorhythms.
# Copyright (C) 2025  Vladyslav Tupikin
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
    dk_sort_iface.cpp
    )

set(DK_SORT_INCLUDE
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_common.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_quicker_asm.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_bubble_quicker.hpp
    ${CMAKE_SOURCE_DIR}/include/dk_sort_iface.hpp
    )

add_executable(${DK_SORT} ${DK_SORT_SRC})

target_include_directories(${DK_SORT} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${DK_SORT} PROPERTIES
    OUTPUT_NAME "${DK_SORT}"
)

#target_compile_options(${DK_SORT} PRIVATE /EHsc /std:c++20 /link /MACHINE:X86 /OUT:dksort_app.exe )
target_compile_options(${DK_SORT} PRIVATE /EHsc /std:c++20 )
