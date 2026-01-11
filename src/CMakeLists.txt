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

target_include_directories(${DK_SORT} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${DK_SORT} PROPERTIES
    OUTPUT_NAME "${DK_SORT}"
)
target_compile_options(${DK_SORT} /EHsc /std:c++20 /MACHINE:X86)
add_executable(${DK_SORT} ${DK_SORT_SRC})
