/*
Test application for different sort algorithms.
Copyright (C) 2026  Vladyslav Tupikin
Co-authored by AI Assistant

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

#ifndef AI_GENERATED_BUBBLE_SORT
#define AI_GENERATED_BUBBLE_SORT

#include "dk_sort_iface.hpp"

namespace dk_sort
{
    class AiGeneratedBubbleSort : public DkSortIface {
    public:
        void DkSortArray(int* array, int size) override;
    };
}

#endif
