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
#include <chrono>
#include <random>
#include <limits>

#include "dk_sort_perfomance.hpp"

dk_perfomance::DkSortPerfomance::DkSortPerfomance(int *arr, int size) {

    this->array_size = size;
    this->array = new int[this->array_size];
        auto start = std::chrono::high_resolution_clock::now();
    for(auto it = 0; it < this->array_size; it++) {
        array[it] = arr[it];
    }
    auto end = std::chrono::high_resolution_clock::now();
    this->duration = end - start;
}

dk_perfomance::DkSortPerfomance::DkSortPerfomance(int size) {

    std::random_device r;
    std::seed_seq seed_seq_gen{r()};
    std::mt19937 gen(seed_seq_gen);
    std::uniform_int_distribution<int> dist(range_min, range_max);

    this->array_size = size;
    this->array = new int[array_size];

    auto start = std::chrono::high_resolution_clock::now();
    for(auto it = 0; it < array_size; it++) {
        array[it] = dist(gen);
    }
    auto end = std::chrono::high_resolution_clock::now();
    this->duration = end - start;
}

dk_perfomance::DkSortPerfomance:: ~DkSortPerfomance() {
    delete[] this->array;
}

double dk_perfomance::DkSortPerfomance::GetWastedTime(void) {
    return this->duration.count();
}

#if defined(ENABLE_PRINT_ARRAY)
void dk_perfomance::DkSortPerfomance::DKSortPrintArray(void) {

    for(auto i = 0; i < this->array_size - 1; i++) {
        if ((this->array[i] > 0 && this->array[i] < 10)) {
            std::cout << " " << this->array[i] << ",";
            continue;
        }
        std::cout << this->array[i] << ",";
    }
    std::cout << array[this->array_size-1]<< std::endl;
}
#else
void dk_perfomance::DkSortPerfomance::DKSortPrintArray(void) { };
#endif
