#include <stdlib.h>

void mx_strdel(char **str) {
    int i = 0;
    if (*str) {
        while (str[i]) {
            int i = 0;
            str[i] = NULL;
            free(str[i]);
            i++;
        }
    }
}


