#include <stdbool.h>

int mx_tolower(int c);
int mx_toupper(int c);
bool mx_islower(int c);
bool mx_isupper(int c);

void mx_reverse_case(char *s) {
    int i = 0;
    while (s[i]) {
        if (mx_islower(s[i]) == 1) {
            s[i] = mx_toupper(s[i]);
        } else if (mx_isupper(s[i]) == 1) {
            s[i] = mx_tolower(s[i]);
        }
        i++;
    }
}


