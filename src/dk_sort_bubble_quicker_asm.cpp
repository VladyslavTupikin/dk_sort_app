/*
Test application for different sort algorhythms.
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

#include "dk_sort_bubble_quicker_asm.hpp"


void dk_sort::DkSortBubbleQuickerAsm::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    int var = size;

    // Algorhytms same as DkSortBubbleQuicker::DkSortArray
    // but tweaked through x86 assembly
    // much faster than DkSortBubbleQuicker::DkSortArray
    // since Windows and Linux inline assembly has different
    // syntax, added macro condition per related OS
#if defined(_WIN32)
    __asm {
        mov esi,array
        mov edi,var
        push ebp
        mov ebp,esi
        xor ebx,ebx
        xor ecx,ecx
    SortStart:
        mov ecx,ebx
    Launch:
        mov eax,dword ptr[ebp+ecx*4]
        mov edx,dword ptr[esi]
        cmp eax,edx
        jge For2
        mov dword ptr[esi],eax
        mov dword ptr[ebp+ecx*4],edx
    For2:
        add ecx,1
        cmp ecx,edi
        jl Launch
        add ebx,1
        add esi,4
        cmp ebx,edi
        jl SortStart
        pop ebp
    }
#elif defined(__linux__)
     __asm__ __volatile__  (
        ".align 32;"
        "mov esi,%0\n\t"
        "mov edi,(%1)\n\t"
        "push ebp\n\t"
        "mov ebp,esi\n\t"
        "xor ebx,ebx\n\t"
        "xor ecx,ecx\n\t"
    "SortStart:\n\t"
        "mov ecx,ebx\n\t"
    "Launch:\n\t"
        "mov eax,dword ptr[ebp+ecx*4]\n\t"
        "mov edx,dword ptr[esi]\n\t"
        "cmp eax,edx\n\t"
        "jge For2\n\t"
        "mov dword ptr[esi],eax\n\t"
        "mov dword ptr[ebp+ecx*4],edx\n\t"
    "For2:\n\t"
        "add ecx,1\n\t"
        "cmp ecx,edi\n\t"
        "jl Launch\n\t"
    "For:\n\t"
        "add ebx,1\n\t"
        "add esi,4\n\t"
        "cmp ebx,edi\n\t"
        "jl SortStart\n\t"
        "pop ebp\n\t"
        "nop\n\t"
        "nop\n\t"::"m"(array),"m"(var):"eax","ebx","ecx","edx","esi","edi","memory"
    );
#endif

}
