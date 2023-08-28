#include "file_to_str.h"

char *mx_strnew(const int size) {
    char *s = (char *)malloc(size + 1);
    if( size < 0) return 0;
    if (s == NULL) return s;
    for (int i = 0; i <= size ; i++) {
        s[i] = '\0';
    }
    return s;
}

