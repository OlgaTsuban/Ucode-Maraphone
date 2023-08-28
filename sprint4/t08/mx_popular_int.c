int mx_popular_int(const int *arr, int size) {
    int count = 0, ex = 0, rest = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > ex) {
            ex = count;
            rest = arr[i];
        }
    }
    return rest;
}
 

