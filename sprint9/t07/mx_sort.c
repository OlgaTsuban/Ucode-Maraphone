#include <stdbool.h>
#include <stdio.h>
void mx_sort(int *arr, int size, bool (*f)(int, int)) {
    if(f != NULL && arr != NULL && size > 0) {
        bool now = false;
        while(!now) {
            now = true;
            for(int i = 0; i < size - 1; i++) {
                if(f(arr[i], arr[i + 1])) {
                    now = false;
                    
                    int t = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = t;
                }
            }
        }
    }
}


