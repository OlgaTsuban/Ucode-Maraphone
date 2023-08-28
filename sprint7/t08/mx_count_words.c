int mx_count_words(const char *str, char delimiter) {
    int count = 0, i = 1;
    while (*str != '\0') {
        if (*str == delimiter) {
            i = 1;
        }
        else if ( i == 1) {
            i = 0;
            count++;
        }
        str++;
    }
    return count;
}


