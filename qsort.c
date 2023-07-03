#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int partition(int *array, int lo, int hi);
void qs(int *array, int lo, int hi);
void quick_sort(int *array, int size);

bool array_compare(int *a, int sa, int *b, int sb);

int main(void) {
    puts("Testing qsort");


    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int res_arr[10] = {0,1,2,3,4,5,6,7,8,9};

    quick_sort(arr, 10);

    assert(array_compare(arr, 10, res_arr, 10));


    puts("all tests passed");

    return EXIT_SUCCESS;
}

int partition(int *array, int lo, int hi) {

    int pivot = array[hi];

    int idx = lo - 1;

    for(int i = lo; i < hi; ++i) {
        if(array[i] <= pivot) {
            idx++;
            int tmp = array[i];
            array[i] = array[idx];
            array[idx] = tmp;
        }
    }

    idx++;
    array[hi] = array[idx];
    array[idx] = pivot;
    
    return idx;
}

void qs(int *array, int lo, int hi) {
   if(lo >= hi) {
        return;
   } 

   int pivot_idx = partition(array, lo, hi);

   qs(array, lo, pivot_idx - 1);
   qs(array, pivot_idx + 1, hi);
}

// compares two arrays of ints
bool array_compare(int *a, int sa, int *b, int sb){
       if(sa != sb) return false; 
       for(int i = 0; i < sa; ++i){
            if(a[i] != b[i]) return false;
       }
       return true;
}

void quick_sort(int *array, int size) {
   qs(array, 0, size - 1); 
}
