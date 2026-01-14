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

#include <iostream>
#include "dk_sort_bubble_optimized.hpp"


void dk_sort::DkSortBubbleOptimized::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    bool swapped = false;
    auto n = size;

    int i = 0;
    int j = 0;

    for ( i = 0; i < n - 1; i++) {

        swapped = false;
        for ( j = 0; j < n - i - 1; j++) {
            if (array[j] > array[ j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }
}
