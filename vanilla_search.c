#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "binary_search.h"

#define ARR_SIZE 1000000

int main() {
    int *arr = (int *)malloc(sizeof(int)* ARR_SIZE);

    /*
     * Initialize the array.
     */
    for (int i = 0; i < ARR_SIZE; i++) {
        if (i == 693201) {
            *(arr+i) = 693200;
        } else {
            *(arr + i) = i;
        }
    }

    /*
     * Print the array.
     *
    for (int i = 0; i < ARR_SIZE; i++) {
        printf("arr[%d] = %d, ", i, arr[i]);
    }
    */


    /*
     * Search for an element 693200, in an efficient way.
     */ 
    for (int i = 0; i < ARR_SIZE; i++) {
        if (arr[i] == 693200) {
            printf("\nVanilla search found 693200 at arr[%d]\n", i);
        }
    }
    //Test case 1 - Element exists.
    int result = binary_search(arr, ARR_SIZE, 693200);
    assert(result = 693200);
    printf("\nTestcase 1 - Binary search found 693200 at arr[%d]\n", result);



    //Test case 2 - Array is empty.
    result = binary_search(NULL, 0, 693200);
    assert(result = -1);
    printf("\nTestcase 2 - Binary didn't find the element in empty array\n");

    //Test case 3 - Element doesn't exist in array.
    result = binary_search(arr, ARR_SIZE, 693201);
    assert(result = -1);
    printf("\nTestcase 3 - Binary didn't find the element in the array\n");

    return 0;
}