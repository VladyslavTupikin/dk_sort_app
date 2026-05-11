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
#include "dk_sort_bubble_quicker.hpp"


void dk_sort::DkSortBubbleQuicker::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    for (auto i = 0; i < size; i++) {
        // Just skip left part of the already sorted elements
        // speed acceleration on 50% comparing to common bubble sort
        // visible starting from 1K elements
        for(auto j = i; j < size ; j++) {
            if(array[j] < array[i]) {
                auto tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}
