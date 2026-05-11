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

#include "dk_sort.hpp"

void test_executor(int array_size) {

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

    auto main_array = new int[array_size];

    auto start = std::chrono::high_resolution_clock::now();
    for(auto it = 0; it < array_size; it++) {
        main_array[it] = dist(gen);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    auto fill_time = duration.count();
    const int second_msec = 1000;

    if(fill_time > second_msec) {
        std::cout << "Array with " << array_size << " elements filled up: " << fill_time / second_msec << " seconds" << std::endl << std::endl;
    }
    else {
        std::cout << "Array with " << array_size << " elements filled up: " << fill_time << " milliseconds" << std::endl << std::endl;
    }

    dk_sort::DkSortBubbleCommon bubble;
    dk_perfomance::DkSortPerfomance bubble_perfom(main_array, array_size);

    std::cout << "Common bubble sort C++ implementation";
    bubble_perfom.DkPerfomanceTest(bubble);

    dk_sort::DkSortBubbleQuicker bubble_quicker;
    dk_perfomance::DkSortPerfomance bubble_quicker_perfom(main_array, array_size);

    std::cout << "Bubble sort quicker C++ implementation";
    bubble_quicker_perfom.DkPerfomanceTest(bubble_quicker);

    dk_sort::DkSortBubbleQuickerAsm bubble_quicker_asm;
    dk_perfomance::DkSortPerfomance bubble_quicker_asm_perfom(main_array, array_size);

    std::cout << "Bubble sort quicker ASM implementation";
    bubble_quicker_asm_perfom.DkPerfomanceTest(bubble_quicker_asm);

    dk_sort::DkSortBubbleOptimized bubble_optimized;
    dk_perfomance::DkSortPerfomance bubble_optimized_perfom(main_array, array_size);

    std::cout << "Optimized Bubble sort C++ implementation";
    bubble_optimized_perfom.DkPerfomanceTest(bubble_optimized);

    dk_sort::DkSortBubbleOptimizedAsm bubble_optimized_asm;
    dk_perfomance::DkSortPerfomance bubble_optimized_perfom_asm(main_array, array_size);

    std::cout << "Optimized Bubble sort ASM implementation";
    bubble_optimized_perfom_asm.DkPerfomanceTest(bubble_optimized_asm);

    dk_sort::AiGeneratedBubbleSort ai_bubble;
    dk_perfomance::DkSortPerfomance ai_bubble_perfom(main_array, array_size);

    std::cout << "AI Generated Bubble Sort implementation";
    ai_bubble_perfom.DkPerfomanceTest(ai_bubble);


    dk_sort::DkSortSelectionCommon selection;
    dk_perfomance::DkSortPerfomance selection_perfom(main_array, array_size);

    std::cout << "Common selection sort C++ implementation";
    selection_perfom.DkPerfomanceTest(selection);

    dk_sort::DkSortInsertionCommon insertion;
    dk_perfomance::DkSortPerfomance insertion_perfom(main_array, array_size);

    std::cout << "Common insertion sort C++ implementation";
    insertion_perfom.DkPerfomanceTest(insertion);

    delete[] main_array;
}
