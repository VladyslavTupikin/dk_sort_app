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

#include "dk_sort_merge_common.hpp"

#include <vector>
#include <iostream>

void static MergeSortImpl(int *array, int size) {

    if (size <= 1) {
        return;
    }

    auto splitSizeA = size / 2;
    auto splitSizeB = size - splitSizeA;
    auto *arrayA = new int[splitSizeA];
    auto *arrayB = new int[splitSizeB];

    for (int i = 0; i < splitSizeA; i++) {
        arrayA[i] = array[i];
    }

    for (int i = 0; i < splitSizeB; i++) {
        arrayB[i] = array[splitSizeA + i];
    }

    MergeSortImpl(arrayA, splitSizeA);
    MergeSortImpl(arrayB, splitSizeB);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < splitSizeA && j < splitSizeB) {
        if (arrayA[i] <= arrayB[j]) {
            array[k] = arrayA[i];
            i++;
        } else {
            array[k] = arrayB[j];
            j++;
        }
        k++;
    }

    while (i < splitSizeA) {
        array[k++] = arrayA[i++];
    }

    while (j < splitSizeB) {
        array[k++] = arrayB[j++];
    }

    delete[] arrayA;
    delete[] arrayB;
}


void dk_sort::DkSortMergeCommon::DkSortArray(int* array, int size) {

    if(!array || size <= 0) {
        return;
    }

    MergeSortImpl(array, size);
}
