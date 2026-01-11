
int get_value(int a[], int size, int i);
void print_array(int arr[],int size);
int exchange_arr_el(int arr[],int size, int pos1, int pos2);
int exchange_arr_el_ptr(int *pos1, int *pos2);
int bubble_sort(int arr[], int size);
int bubble_sort_quicker(int arr[], int size);
int bubble_sort_optimized(int arr[], int size);

int cb_compare_integers_qsort(const void* a, const void* b);
void bubble_sort_quicker_asm(int arr[], int size);
void bubble_sort_quicker_asm_optimized(int arr[], int size);
void bubble_sort_optimized_asm(int arr[], int size);
