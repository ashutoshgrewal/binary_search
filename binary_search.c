#include <stdio.h>
#include <inttypes.h>
#include "binary_search.h"

static int
binary_search_subr (int *arr, int64_t min_index, int64_t max_index, int value)
{
    printf("min_index = %" PRId64 " , max_index = %" PRId64 "", min_index, max_index);
    if (min_index > max_index) {
        printf("Didn't find the element.\n");
        return -1;
    }
    int64_t mid_index = (max_index + min_index) / 2;
    printf(" mid_index = %" PRId64 " and arr[mid_index] = %d", mid_index, arr[mid_index]);
    if (arr[mid_index] == value) {
        return mid_index;
    } else if (value > arr[mid_index]) {
        printf("\nGoing right\n");
        return binary_search_subr(arr, mid_index + 1, max_index, value);
    } else {
         printf("\nGoing left\n");
        return binary_search_subr(arr, min_index, mid_index - 1, value);
    }
}

int
binary_search (int *arr, uint64_t arr_size, int value)
{
    return binary_search_subr(arr, 0, arr_size - 1, value);
}