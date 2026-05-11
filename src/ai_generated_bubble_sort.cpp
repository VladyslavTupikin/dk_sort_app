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

#include <algorithm>
#include "ai_generated_bubble_sort.hpp"

namespace dk_sort
{
    void AiGeneratedBubbleSort::DkSortArray(int* array, int size) {
        if (!array || size <= 1) {
            return;
        }

        for (int i = 0; i < size - 1; ++i) {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; ++j) {
                if (array[j] > array[j + 1]) {
                    std::swap(array[j], array[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
}
