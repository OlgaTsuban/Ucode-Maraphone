#include <unistd.h>

void mx_printchar(char c);

void mx_pyramid(int n) {
    int k = 1;
    int i;
    if (n <= 1 ||  n % 2 != 0) {
        return;
    }
    for (int j = 0; j < n - 1; j++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    mx_printchar('\\');
    mx_printchar('\n');
    for (i = 1; i < n / 2; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int j = 0; j < k; j++) {
            mx_printchar(' ');
        }
        mx_printchar('\\');
        for (int j = 0; j < i; j++) {
            mx_printchar(' ');
        }
        mx_printchar('\\');
        mx_printchar('\n');
        k += 2;
    }
    for (int t = 1; t < n / 2; t++) {
        for (int j = 0; j < n - i - 1; j++) {
            mx_printchar(' ');
        }
        mx_printchar('/');
        for (int j = 0; j < k; j++) {
            mx_printchar(' ');
        }
        k += 2;
        mx_printchar('\\');
        for (int j = 0; j < n - i - 1; j++) {
            mx_printchar(' ');
        }
        mx_printchar('|');
        mx_printchar('\n');
        i++;
    }
    mx_printchar('/');
    for (int j = 0; j < 2 * n - 3; j++) {
        mx_printchar('_');
    }
    mx_printchar('\\');
    mx_printchar('|');
    mx_printchar('\n');
}


