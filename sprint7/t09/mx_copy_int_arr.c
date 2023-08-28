#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL) return 0;
    int *arr = malloc(size);
    if (arr == NULL) return 0;
    if (size < 1) return 0;
    for (int i = 0; i < size; i++) {
        arr[i] = src[i];
    }
    return arr;
}


