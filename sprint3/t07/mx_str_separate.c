#include <unistd.h>

void mx_printchar(char c);
void mx_str_separate(const char *str, char delim) {
    int count = 0;
    while (1) {
        if (str[count] == '\0') {
            break;
        }
        if (str[count] == delim) {
            if (str[count + 1] == delim) {
                count++;
                continue;
            }
            write(1, "\n", 1);
        }
        else {
            mx_printchar(str[count]);
        }
        count++;
    }
    write(1, "\n", 1);
}

 
