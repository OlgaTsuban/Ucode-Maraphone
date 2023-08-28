#include <unistd.h>
int main(int argc, char *argv[]) {
    char s = '\n';
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            char *p = argv[i];
            while (*p != '\0') {
                write(1, p++, 1);
            }
            write (1, &s, 1);
        }
    }
    return 0;
}


