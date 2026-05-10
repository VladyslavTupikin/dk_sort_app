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

#include "dk_sort_insertion_common.hpp"


void dk_sort::DkSortInsertionCommon::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    for (auto i = 1; i < size; i++) {
        auto key = array[i];
        auto j = i - 1;

        while(j >= 0 && key < array[j]) {
            array[j + 1] =  array[j];
            j--;
        }

        array[j + 1] = key;
    }
}
