#include "duplicate.h"

int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL) return NULL;
    if (size < 1) return NULL;
    int *ar = malloc(size * 4);
    if (ar == NULL) return NULL;
    for (int i = 0; i < size; i++) {
        ar[i] = src[i];
    }
    return ar;
}


