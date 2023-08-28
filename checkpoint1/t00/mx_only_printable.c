#include <unistd.h>

void mx_only_printable(void) {
    for (int i = 126; i > 31; i--) {
        write(1, &i, 1);
    }
    write(1, "\n", 1);
}


