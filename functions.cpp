#include <iostream>
#include "functions.hpp"

int get_value(int a[], int size, int i) {
    if (i >= 0 && i < size) {
        return a[i];
    }

    return -1;
}

void print_array(int *arr,int size) {
    for(auto i = 0; i < size - 1; i++) {
        if ((arr[i] > 0 && arr[i] < 10)) {
            std::cout << " " << arr[i] << ",";
            continue;
        }
        std::cout << arr[i] << ",";
    }
    std::cout << arr[size-1]<< std::endl;
}

int exchange_arr_el(int arr[],int size, int pos1, int pos2) {

    if (    (!arr) ||
            (pos1 < 0 || pos1 >= size) ||
            (pos2 < 0 || pos2 >= size)) {
        goto Err;
    }

    std::cout << "Exchange arr[" << pos1 << "] = " << arr[pos1] << " with arr[" << pos2 << "] = " << arr[pos2] << std::endl;

    auto temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;

    return 0;
Err:
    std::cout << "Invalid input: " << __func__ <<std::endl;
    return -1;
}

int exchange_arr_el_ptr(int *pos1, int *pos2) {

    if ( !pos1 || !pos2) {
        goto Err;
    }

    //std::cout << "Exchange arr[" << pos1 << "] = " << *pos1 << " with arr[" << pos2 << "] = " << *pos2 << std::endl;

    auto temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;

    return 0;
Err:
    std::cout << "Invalid input: " << __func__ <<std::endl;
    return -1;
}

int bubble_sort(int arr[], int size) {

    if(!arr || size <= 0) {
        return -1;
    }

    for (auto i = 0; i < size; i++) {
        for(auto j = 0; j < size ; j++) {

            if(arr[j] > arr[i]) {
                auto tmp = arr[i];
                exchange_arr_el_ptr(&arr[i], &arr[j]);
            }
        }
    }
    return 0;
}

int bubble_sort_quicker(int arr[], int size) {
    if(!arr || size <= 0) {
        return -1;
    }

    for (auto i = 0; i < size; i++) {
        for(auto j = i; j < size ; j++) {
            if(arr[j] < arr[i]) {
                auto tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    return 0;
}


int bubble_sort_optimized(int arr[], int size) {

    bool swapped;
    auto n = size;
    if(!arr || size <= 0) {
        return -1;
    }
    int i,j;

    for ( i = 0; i < n - 1; i++) {

        swapped = false;
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[ j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
            break;
        }
    }

    return 0;
}

int cb_compare_integers_qsort(const void* a, const void* b) {
    const int* arg1 = static_cast<const int*>(a);
    const int* arg2 = static_cast<const int*>(b);

    if (*arg1 < *arg2) return -1;
    if (*arg1 > *arg2) return 1;
    return 0;
}


void bubble_sort_quicker_asm(int arr[], int size) {
    int var = size;
    int temp = 0;

#if defined(_WIN32)
    __asm {
        mov esi,arr
        mov edi,var
        xor ebx,ebx
        xor ecx,ecx
    SortStart:
        cmp ecx,edi
        jg For
        mov eax,dword ptr[esi+ebx*4]
        mov edx,dword ptr[esi+ecx*4]
        cmp edx,eax
        jg For2
        mov temp,eax
        mov dword ptr[esi+ebx*4],edx
        mov eax,temp
        mov dword ptr[esi+ecx*4],eax
    For2:
        add ecx,1
        cmp ecx,edi
        jl SortStart
    For:
        add ebx,1
        mov ecx,ebx
        cmp ebx,edi
        jl SortStart
    }
#elif defined(__linux__)
     __asm__ __volatile__  (
        "mov esi,%0\n\t"
        "mov edi,(%1)\n\t"
        "xor ebx,ebx\n\t"
        "xor ecx,ecx\n\t"
    "SortStart:\n\t"
        "cmp ecx,edi\n\t"
        "jg For\n\t"
        "mov eax,dword ptr[esi+ebx*4]\n\t"
        "mov edx,dword ptr[esi+ecx*4]\n\t"
        "cmp edx,eax\n\t"
        "jg For2\n\t"
        "mov (%2),eax\n\t"
        "mov dword ptr[esi+ebx*4],edx\n\t"
        "mov eax,(%2)\n\t"
        "mov dword ptr[esi+ecx*4],eax\n\t"
    "For2:\n\t"
        "add ecx,1\n\t"
        "cmp ecx,edi\n\t"
        "jl SortStart\n\t"
    "For:\n\t"
        "add ebx,1\n\t"
        "mov ecx,ebx\n\t"
        "cmp ebx,edi\n\t"
        "jl SortStart\n\t"::"m"(arr),"m"(var),"m"(temp):"eax","ebx","ecx","edx","esi","edi","memory"
    );
#endif

}


void bubble_sort_optimized_asm(int arr[], int size) {

    int n = size;
    int temp = 0;
#if defined(_WIN32)
    __asm {
        push ebp
        mov esi,arr
        mov edi,n
        dec edi
        xor ebx,ebx
        jmp For
    Input:
        xor ebp,ebp
        xor edx,edx
    For2:
        mov eax,dword ptr[esi+edx*4]
        mov ecx,dword ptr[esi+edx*4+4]
        cmp eax,ecx
        jle Next
        mov dword ptr[esi+edx*4],ecx
        mov dword ptr[esi+edx*4+4],eax
        mov ebp,1
    Next:
        inc edx
        mov eax,edi
        sub eax,ebx
        cmp edx,eax
        jl For2
        test ebp,0FFFFFFFFh
        je Return
        inc ebx
    For:
        cmp ebx,edi
        jl Input
    Return:
        pop ebp
        mov eax,esi
    }
#elif defined(__linux__)
    __asm__ __volatile__ (
        "mov esi,%0\n\t"
        "mov edi,(%2)\n\t"
        "dec edi\n\t"
        "xor ebx,ebx\n\t"
        "jmp for\n\t"
    "Input:\n\t"
        "xor edx,edx\n\t"
    "for2:\n\t"
        "mov eax,dword ptr[esi+edx*4]\n\t"
        "mov ecx,dword ptr[esi+edx*4+4]\n\t"
        "cmp eax,ecx\n\t"
        "jle Next\n\t"
        "mov dword ptr[esi+edx*4],ecx\n\t"
        "mov dword ptr[esi+edx*4+4],eax\n\t"
        "mov (%2),1\n\t"
    "Next:\n\t"
        "inc edx\n\t"
        "mov eax,edi\n\t"
        "sub eax,ebx\n\t"
        "cmp edx,eax\n\t"
        "jl for2\n\t"
        "test (%2),0xFFFFFFFF\n\t"
        "je Return\n\t"
        "inc ebx\n\t"
    "for:\n\t"
        "cmp ebx,edi\n\t"
        "jl Input\n\t"
    "Return:\n\t"
        "mov eax,esi\n\t"::"m"(arr),"m"(n),"m"(temp):"eax","ebx","ecx","edx","esi","edi","memory"
    );
#endif
}

void bubble_sort_quicker_asm_optimized(int arr[], int size) {
    int var = size;

#if defined(_WIN32)
    __asm {
        mov esi,arr
        mov edi,var
        push ebp
        mov ebp,esi
        xor ebx,ebx
        xor ecx,ecx
    SortStart:
        mov ecx,ebx
    Launch:
        mov eax,dword ptr[ebp+ecx*4]
        mov edx,dword ptr[esi]
        cmp eax,edx
        jge For2
        mov dword ptr[esi],eax
        mov dword ptr[ebp+ecx*4],edx
    For2:
        add ecx,1
        cmp ecx,edi
        jl Launch
    For:
        add ebx,1
        add esi,4
        cmp ebx,edi
        jl SortStart
        pop ebp
    }
#elif defined(__linux__)
     __asm__ __volatile__  (
        "mov esi,%0\n\t"
        "mov edi,(%1)\n\t"
        "push ebp\n\t"
        "mov ebp,esi\n\t"
        "xor ebx,ebx\n\t"
        "xor ecx,ecx\n\t"
    "SortStart:\n\t"
        "mov ecx,ebx\n\t"
    "Launch:\n\t"
        "mov eax,dword ptr[ebp+ecx*4]\n\t"
        "mov edx,dword ptr[esi]\n\t"
        "cmp eax,edx\n\t"
        "jge For2\n\t"
        "mov dword ptr[esi],eax\n\t"
        "mov dword ptr[ebp+ecx*4],edx\n\t"
    "For2:\n\t"
        "add ecx,1\n\t"
        "cmp ecx,edi\n\t"
        "jl Launch\n\t"
    "For:\n\t"
        "add ebx,1\n\t"
        "add esi,4\n\t"
        "cmp ebx,edi\n\t"
        "jl SortStart\n\t"
        "pop ebp\n\t"
        "nop\n\t"
        "nop\n\t"::"m"(arr),"m"(var),"m"(temp):"eax","ebx","ecx","edx","esi","edi","memory"
    );
#endif

}

