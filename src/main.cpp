/*
Library for work with DNS messages.
Copyright (C) 2025  Vladyslav Tupikin

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

#include "functions.hpp"
#define ARR_SIZE 20

#if 0
    #define PRINT_ARRAY_MACRO(array,size) ;
#else
    #define PRINT_ARRAY_MACRO(array,size) \
    do {                            \
        print_array(array, size);   \
    }  while(0)
#endif

#define PRINT_EXEC_TIME(MSEC)                                                       \
do {                                                                                \
    if(MSEC > 1000) {                                                               \
        std::cout << "Execution time: " << MSEC/1000 << " seconds" << std::endl << std::endl;    \
    }                                                                               \
    else {                                                                          \
        std::cout << "Execution time: " << MSEC << " milliseconds" << std::endl << std::endl;    \
    }                                                                               \
}while(0)

#define GOOGLE 1
#define ASMASTERY 1
#define COMMON_BUBBLE 1
#define DK_SORT 1


int main(int argc, char **argv) {

    auto pos1 = 2;
    auto pos2 = 5;
    auto range_min = 1;
    auto range_max = 99;
    int ret = 0;
    std::time_t currentTime = std::time(nullptr);


    //std::cout << "Array Index: " << 5 << "  Array value: " << get_value(arr,6,5) << std::endl;
    //const int array_size = ARR_SIZE;
    auto bubble = new int[ARR_SIZE];
    auto bubble_quick = new int[ARR_SIZE];
    auto bubble_asmastery = new int[ARR_SIZE];
    auto bubble_google_ai = new int[ARR_SIZE];
    auto bubble_quick_asm = new int[ARR_SIZE];
    auto bubble_asmastery_asm = new int[ARR_SIZE];
    //int bubble_quick_asm[ARR_SIZE] = {0};
    std::random_device r;
    std::seed_seq seed_seq_gen{r()};
    std::mt19937 gen(seed_seq_gen);
    std::uniform_int_distribution<int> dist(1, 99);


    std::cout << std::endl << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    for(auto it = 0; it < ARR_SIZE; it++) {
        bubble[it] = dist(gen);
        bubble_quick[it] = bubble[it];
        bubble_asmastery[it] = bubble[it];
        bubble_google_ai[it] = bubble[it];
        bubble_quick_asm[it] = bubble[it];
        bubble_asmastery_asm[it] = bubble[it];
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Current time: " << std::ctime(&currentTime);
    std::cout << "Randomly filled up array with " << ARR_SIZE << " elements, range from " << range_min << " to "<< range_max << std::endl;
    PRINT_EXEC_TIME(duration.count());

#if COMMON_BUBBLE
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Bubble sort array with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble, ARR_SIZE);
    ret = bubble_sort(bubble,ARR_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    if (ret != -1) {
        PRINT_ARRAY_MACRO(bubble, ARR_SIZE);
        PRINT_EXEC_TIME(duration.count());
    }
#endif

#if DK_SORT
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Bubble sort array via __asm with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble_quick_asm, ARR_SIZE);
    bubble_sort_quicker_asm(bubble_quick_asm, ARR_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    PRINT_ARRAY_MACRO(bubble_quick_asm, ARR_SIZE);
    PRINT_EXEC_TIME(duration.count());

    start = std::chrono::high_resolution_clock::now();
    std::cout << "Quick Bubble sort array with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble_quick, ARR_SIZE);
    ret = bubble_sort_quicker(bubble_quick,ARR_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    if (ret != -1) {
        PRINT_ARRAY_MACRO(bubble_quick, ARR_SIZE);
        PRINT_EXEC_TIME(duration.count());
    }
#endif

#if ASMASTERY
    start = std::chrono::high_resolution_clock::now();
    std::cout << "ASMastery Quick Bubble sort array with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble_asmastery, ARR_SIZE);
    ret = bubble_sort_optimized(bubble_asmastery,ARR_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    if (ret != -1) {
        PRINT_ARRAY_MACRO(bubble_asmastery, ARR_SIZE);
        PRINT_EXEC_TIME(duration.count());
    }

    start = std::chrono::high_resolution_clock::now();
    std::cout << "ASMastery Quick Bubble sort array via __asm with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble_asmastery_asm, ARR_SIZE);
    bubble_sort_optimized_asm(bubble_asmastery_asm,ARR_SIZE);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    if (ret != -1) {
        PRINT_ARRAY_MACRO(bubble_asmastery_asm, ARR_SIZE);
        PRINT_EXEC_TIME(duration.count());
    }

#endif

#if GOOGLE
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Google AI Quick sort array with " << ARR_SIZE << " elements" << std::endl;
    PRINT_ARRAY_MACRO(bubble_google_ai, ARR_SIZE);
    qsort(bubble_google_ai, ARR_SIZE, sizeof(int), &cb_compare_integers_qsort);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;

    PRINT_ARRAY_MACRO(bubble_google_ai, ARR_SIZE);
    PRINT_EXEC_TIME(duration.count());
#endif


    delete[] bubble;
    delete[] bubble_quick;
    delete[] bubble_asmastery;
    delete[] bubble_google_ai;
    delete[] bubble_quick_asm;
    delete[] bubble_asmastery_asm;

    return 0;
}
