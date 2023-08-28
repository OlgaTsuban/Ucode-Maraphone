#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    if (src == NULL) return NULL;
    int t[src_size];
    int count = 0;
    for (int i = 0; i < src_size; i++) {
        int dup = 0;
        for(int j = 0; j < i; j++) {
            if(src[i] == src[j]) {
                dup = 1;
            }
        }
        if (dup) {
            continue;
        }
        t[count] = src[i];
        count++;
    }
    int *result = mx_copy_int_arr(t, count);
    *dst_size = count;
    return result;
}
 
 

