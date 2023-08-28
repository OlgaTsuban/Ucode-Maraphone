#include <unistd.h>

void mx_printstr(const char *s) {
    int account = 0;
    while (s[account] != '\0') {
        account++;
    }
    write(1, s, account);
}

 
