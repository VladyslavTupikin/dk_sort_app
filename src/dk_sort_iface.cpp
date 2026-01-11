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
#include <chrono>
#include <random>
#include <limits>

#include "dk_sort_iface.hpp"

#define PRINT_EXEC_TIME(MSEC)                                                       \
do {                                                                                \
    if(MSEC > 1000) {                                                               \
        std::cout << "Execution time: " << MSEC/1000 << " seconds" << std::endl << std::endl;    \
    }                                                                               \
    else {                                                                          \
        std::cout << "Execution time: " << MSEC << " milliseconds" << std::endl << std::endl;    \
    }                                                                               \
}while(0)

void dk_sort::DkSortIface::DkSortPerfomance() {

    std::random_device r;
    std::seed_seq seed_seq_gen{r()};
    std::mt19937 gen(seed_seq_gen);
    std::uniform_int_distribution<int> dist(range_min, range_max);

    auto array = new int[ARRAY_SIZE];

    std::time_t currentTime = std::time(nullptr);
    std::cout << "Current time: " << std::ctime(&currentTime);
    auto start = std::chrono::high_resolution_clock::now();

    for(auto it = 0; it < ARRAY_SIZE; it++) {
        array[it] = dist(gen);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Randomly filled up array with " << ARRAY_SIZE << " elements, range from " << range_min << " to "<< range_max << std::endl;
    PRINT_EXEC_TIME(duration.count());

    start = std::chrono::high_resolution_clock::now();
    std::cout << "Sorting array with " << ARRAY_SIZE << " elements" << std::endl;

    DKSortPrintArray();
    DkSortArray(array,ARRAY_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    DKSortPrintArray();
    PRINT_EXEC_TIME(duration.count());

    delete[] array;
}

void dk_sort::DkSortIface::DKSortPrintArray() {

    for(auto i = 0; i < ARRAY_SIZE - 1; i++) {
        if ((array[i] > 0 && array[i] < 10)) {
            std::cout << " " << array[i] << ",";
            continue;
        }
        std::cout << array[i] << ",";
    }
    std::cout << array[ARRAY_SIZE-1]<< std::endl;
}
