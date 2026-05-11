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

#define PRINT_EXEC_TIME(MSEC)                                                                   \
do {                                                                                            \
    if(MSEC > 1000) {                                                                           \
        std::cout << "Execution time: " << MSEC/1000 << " seconds" << std::endl << std::endl;   \
    }                                                                                           \
    else {                                                                                      \
        std::cout << "Execution time: " << MSEC << " milliseconds" << std::endl << std::endl;   \
    }                                                                                           \
}while(0)

template <typename T>
void dk_perfomance::DkSortPerfomance:: DkPerfomanceTest(T &obj) {

#if defined(ENABLE_PRINT_ARRAY)
    std::time_t currentTime = std::time(nullptr);
    std::cout << std::endl << "Current time: " << std::ctime(&currentTime);

    std::cout << "Randomly filled up array with " << this->array_size << " elements, range from " << range_min << " to "<< range_max << std::endl;
    DKSortPrintArray();
#endif

    std::cout << std::endl << "Sorting array with " << this->array_size << " elements" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    obj.DkSortArray(this->array, this->array_size);

    auto end = std::chrono::high_resolution_clock::now();
    this->duration = end - start;

    DKSortPrintArray();

    PRINT_EXEC_TIME(this->duration.count());
}
