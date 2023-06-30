#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>


int linear_search(int* array, int size, int value) {
    for(int i = 0; i < size; ++i) {
        if(array[i] == value) return i;
    }
    return -1;
}

// array must be sorted min at index 0
int binary_search(int* array, int size, int value) {

    int lo = 0;
    int hi = size;
    int index = 0;
    int guess = 0;

    do {
        index = lo + (hi - lo) / 2; 
        guess = array[index];

        if(guess == value) {
            return index;
        } else if(guess > value) {
            hi = index;
        } else {
            lo = index + 1;
        }

    } while(lo < hi);

    return -1;
}


int two_crystal_balls(bool *array, int size) {
    
    int jmp_val = floor(sqrt(size));
    int i = jmp_val;

    for(; i< size; i += jmp_val) {
        if(array[i]) {
            break;
        }
    }

    i -= jmp_val;

    for(int j = 0; (j < jmp_val) && (i < size); ++j, ++i) {
        if(array[i]) {
           return i; 
        }
    }

    return -1;
}


void bubble_sort(int *array, int size) {

    int temp = 0;
    for(int i = size; i != 0; --i) {
       for(int j = 0; (j < i) && (j != (size - 1)); ++j) {
            if(array[j] > array[j + 1]) {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
       } 
    }
}

// compares to arrays of ints
bool array_compare(int *a, int sa, int *b, int sb){
       if(sa != sb) return false; 
       for(int i = 0; i < sa; ++i){
            if(a[i] != b[i]) return false;
       }
       return true;
}

int main(void) {

    puts("Testing algs!");

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int size = 10;

    puts("Testing linear search");
    int index = linear_search(arr, size, 6);
    assert( index == 6);


    puts("Testing binary search");
    index = binary_search(arr, size, 6);
    assert( index == 6);

    index = binary_search(arr, size, 0);
    assert(index == 0);

    index = binary_search(arr, size, 9);
    assert(index == 9);

    index = binary_search(arr, size, 10);
    assert(index == -1);
    
    bool crystal[10] = {false, false, false, false, true, true, true, true, true, true};

    puts("testing two crystal balls");
    index = two_crystal_balls(crystal, size);
    assert(index == 4);

    int not_sorted[10] = {9,8,7,6,5,4,3,2,1,0};
    puts("testing bubble sort");
    bubble_sort(not_sorted, size);
    assert(array_compare(not_sorted, size, arr, size));

    puts("Finished testing");
    return EXIT_SUCCESS;
}
