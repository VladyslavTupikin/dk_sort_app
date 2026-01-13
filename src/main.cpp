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

#include "dk_sort.hpp"
#define ARRAY_SIZE 20000


int main(int argc, char **argv) {

    /*
        For testing all sort methods on the same data, need to generate
        array main_array here and provide it to the DkSortPerfomance constructor
        per sort method.
    */
    std::random_device r;
    std::seed_seq seed_seq_gen{r()};
    std::mt19937 gen(seed_seq_gen);

    const int range_min = 1;
    const int range_max = 99;

    std::uniform_int_distribution<int> dist(range_min, range_max);

    auto main_array = new int[ARRAY_SIZE];

    auto start = std::chrono::high_resolution_clock::now();
    for(auto it = 0; it < ARRAY_SIZE; it++) {
        main_array[it] = dist(gen);
    }

    dk_sort::DkSortBubbleCommon bubble;
    dk_perfomance::DkSortPerfomance bubble_perfom(main_array, ARRAY_SIZE);

    std::cout << "Common bubble sort";
    bubble_perfom.DkPerfomanceTest(bubble);


    dk_sort::DkSortBubbleQuicker bubble_quicker;
    dk_perfomance::DkSortPerfomance bubble_quicker_perfom(main_array, ARRAY_SIZE);

    std::cout << "Bubble sort quicker";
    bubble_quicker_perfom.DkPerfomanceTest(bubble_quicker);

    dk_sort::DkSortBubbleQuickerAsm bubble_quicker_asm;
    dk_perfomance::DkSortPerfomance bubble_quicker_asm_perfom(main_array, ARRAY_SIZE);

    std::cout << "Bubble sort quicker ASM implementation";
    bubble_quicker_asm_perfom.DkPerfomanceTest(bubble_quicker_asm);

    delete[] main_array;

    return 0;
}
