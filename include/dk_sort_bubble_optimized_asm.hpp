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

#ifndef DK_SORT_BUBBLE_OPTIMIZED_ASM
#define DK_SORT_BUBBLE_OPTIMIZED_ASM

#include "dk_sort_iface.hpp"

namespace dk_sort
{
    class DkSortBubbleOptimizedAsm:DkSortIface {
        public:
            void DkSortArray(int*,int) override;
    };
}

#endif
