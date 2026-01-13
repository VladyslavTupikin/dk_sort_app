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

#ifndef DK_SORT_PERFOMANCE
#define DK_SORT_PERFOMANCE

#include <iostream>
#include "dk_sort_bubble_common.hpp"
#include "dk_sort_bubble_quicker.hpp"

namespace dk_perfomance
{
    class DkSortPerfomance {

        public:
        //DkSortPerfomance();
            DkSortPerfomance(int *arr,int size);
            DkSortPerfomance(int size);
            virtual ~DkSortPerfomance();

            double GetWastedTime(void);
            void DKSortPrintArray(void);

            template <typename T>
            void DkPerfomanceTest( T& obj);

        private:
            int* array = nullptr;
            int array_size = 0;
            const int range_min = 1;
            const int range_max = 99;

            std::chrono::duration<double, std::milli> duration;
    };
}

#include "dk_sort_perfomance.tpp"

#endif
