#include "file_to_str.h"

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *dup = mx_strnew(size);
    if( dup == 0) return NULL;
    mx_strcpy(dup, str);
    return dup;
}

