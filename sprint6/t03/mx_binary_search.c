int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int end = size - 1;
    int begin = 0;
    (*count) = 0;
    if (!*arr) {
        return -1;
    }
    while (begin <= end) {
            (*count)++;
        int mid = (begin + end) / 2;
            if (mx_strcmp(arr[mid], s) < 0)
                begin = mid + 1;
            else if (mx_strcmp (arr[mid], s) == 0) {
                return mid;
            }
            else
                end = mid - 1;
        }
        if (begin > end) {
            *count = 0;
            return -1;
        }
        return -1;
}



