#include <unistd.h>

void  mx_printstr(const char* s);

int mx_strlen(char* s);

void mx_is_positive(int i) {
    if (i > 0) {
       char s[] = "positive";
        mx_printstr(s);
        write(1, "\n", 1);
    }
    if (i < 0) {
        char s[] = "negative";
        mx_printstr(s);
        write(1, "\n", 1);
    }
    if (i == 0) {
        char s[] = "zero";
        mx_printstr(s);
        write(1, "\n", 1);
    }
}
 

