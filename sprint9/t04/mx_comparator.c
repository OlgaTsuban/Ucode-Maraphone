#include <stdbool.h>
#include <stdio.h>
int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int)) {
    if ( arr == NULL || compare == NULL || size < 1) return -1;
    for (int y = 0; y < size; y++) {
      if (compare(arr[y], x))
          return y;
    }
    return -1;
}



