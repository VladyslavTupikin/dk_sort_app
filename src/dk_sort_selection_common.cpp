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

#include <map>
#include <iostream>

#include "dk_sort_selection_common.hpp"

std::pair<int, int> findMinArray(int* array, int size, int start) {

    int minIdx = start;
    int minVal = array[start];

    for (int i = start; i < size; i++) {
        if (minVal > array[i]) {
            minIdx = i;
            minVal = array[i];
        }
    }

    return {minIdx, minVal};
}

void dk_sort::DkSortSelectionCommon::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    for (int i = 0; i < size; i++) {
        auto minimal = findMinArray(array, size, i);

        if (i != minimal.first) {
            std::swap(array[i], array[minimal.first]);
        }
    }
}
