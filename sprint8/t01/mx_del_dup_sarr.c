#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL) return NULL;
    t_intarr temp;
    temp.size = src->size;
    temp.arr = (int*)malloc(temp.size * sizeof(int));
    int count = 0;
    if (temp.arr == NULL) return NULL;
    for (int i = 0; i < src->size; i++) {
        int D = 0;
        for (int j = 0; j < i; j++) {
            if (src->arr[j] == src->arr[i]){
                D = 1;
            }
        }
        if (D) {
            continue;
        }
        temp.arr[count] = src->arr[i];
        count++;
    }
    t_intarr *res = (t_intarr*)malloc(sizeof(t_intarr));
    res->size = count;
    res->arr = mx_copy_int_arr(temp.arr, count);
    free(temp.arr);
    temp.arr = NULL;
    return res;
}


