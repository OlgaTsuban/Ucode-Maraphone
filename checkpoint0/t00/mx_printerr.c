#include <unistd.h>

void mx_printerr(const char *s) {
    int j = 0;
    while (s[j] != '\0') {
        j++;
    }
    write(2, s, j);
}


