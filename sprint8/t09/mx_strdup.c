#include "only_smiths.h"

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *dup = mx_strnew(size);
    if( dup == 0) return NULL;
    mx_strcpy(dup, str);
    return dup;
}


