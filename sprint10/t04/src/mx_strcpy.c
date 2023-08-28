#include "../inc/header.h"

char *mx_strcpy(char *dst, const char *src) {
    char *temp = dst;

    while (*src) {
        *dst++ = *src++;
    }
    *dst = 0;
    return temp;
}


