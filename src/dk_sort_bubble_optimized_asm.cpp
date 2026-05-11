/*
Test application for different sort algorithms.
Copyright (C) 2026  Vladyslav Tupikin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "dk_sort_bubble_optimized_asm.hpp"


void dk_sort::DkSortBubbleOptimizedAsm::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    // Algorhytms same as DkSortBubbleOptimized::DkSortArray
    // but tweaked through x86 assembly
    // should be faster than DkSortBubbleOptimized::DkSortArray
    // since Windows and Linux inline assembly has different
    // syntax, added macro condition per related OS
#if defined(_WIN32)
    int n = size; // Win32 requires local variable :/
    __asm {
        push ebp
        mov esi,array
        mov edi,n
        dec edi
        xor ebx,ebx
        jmp For
    Input:
        xor ebp,ebp
        xor edx,edx
    For2:
        mov eax,dword ptr[esi+edx*4]
        mov ecx,dword ptr[esi+edx*4+4]
        cmp eax,ecx
        jle Next
        mov dword ptr[esi+edx*4],ecx
        mov dword ptr[esi+edx*4+4],eax
        mov ebp,1
    Next:
        inc edx
        mov eax,edi
        sub eax,ebx
        cmp edx,eax
        jl For2
        test ebp,0FFFFFFFFh
        je Return
        inc ebx
    For:
        cmp ebx,edi
        jl Input
    Return:
        pop ebp
        mov eax,esi
    }
#elif defined(__linux__)
    int is_swapped = 0;
    __asm__ __volatile__ (
        ".align 32;"
        "mov esi,%0\n\t"
        "mov edi,(%1)\n\t"
        "dec edi\n\t"
        "xor ebx,ebx\n\t"
        "jmp for\n\t"
    "Input:\n\t"
        "xor edx,edx\n\t"
    "for2:\n\t"
        "mov eax,dword ptr[esi+edx*4]\n\t"
        "mov ecx,dword ptr[esi+edx*4+4]\n\t"
        "cmp eax,ecx\n\t"
        "jle Next\n\t"
        "mov dword ptr[esi+edx*4],ecx\n\t"
        "mov dword ptr[esi+edx*4+4],eax\n\t"
        "mov (%2),1\n\t"
    "Next:\n\t"
        "inc edx\n\t"
        "mov eax,edi\n\t"
        "sub eax,ebx\n\t"
        "cmp edx,eax\n\t"
        "jl for2\n\t"
        "test (%2),0xFFFFFFFF\n\t"
        "je Return\n\t"
        "inc ebx\n\t"
    "for:\n\t"
        "cmp ebx,edi\n\t"
        "jl Input\n\t"
    "Return:\n\t"
        "mov eax,esi\n\t"::"m"(array),"m"(size),"m"(is_swapped):"eax","ebx","ecx","edx","esi","edi","memory"
    );
#endif
}
