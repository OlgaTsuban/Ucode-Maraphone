#include <stdbool.h>

bool mx_isdigit(int c);

bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int i = 0, s = 1, b = 0, MAX = 2147483647, MIN = -2147483648;
    while (mx_isspace(str[i])) {
        i++;
    }
    if (str[i] == '-' || str[i] == '+') {
        s = 1 - 2 * (str[i++] == '-');
    }
   while (mx_isdigit(str[i])) {
        if (b > MAX / 10 || (b == MAX / 10 && str[i] - '0' > 7)) {
            if (s == 1) {
                return MAX;
            }
            else return MIN;
        }
        b = 10 * b + (str[i++] - '0');
    }
    return b * s;
}
 

