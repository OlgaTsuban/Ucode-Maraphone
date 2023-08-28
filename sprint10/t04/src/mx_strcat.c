#include "../inc/header.h"

char *mx_strcat(char *s1, const char *s2) {
    char *result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    for(int i = 0; i < mx_strlen(s1); i++) {
        result[i] = s1[i];
    }

    for (int i = mx_strlen(s1), j = 0; j < mx_strlen(s2); i++, j++) {
    result[i] = s2[j];
    }

    return result;
}

