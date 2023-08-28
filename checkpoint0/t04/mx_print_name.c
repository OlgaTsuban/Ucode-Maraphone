#include <unistd.h>

static void mx_printchar(char c) {
    write (1, &c, 1);
}

static void mx_printstr(const char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    write (1, s, i);
}
static void mx_printint(int n) {
    char array[50];
    int i = 0;
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    }
    if (n == 0) {
        write(1, "0", 1);
    }
    if (n < 0 && n != -2147483648) {
        n *= -1;
        write(1, "-", 1);
    }
    while (n != 0 && n != -2147483648) {
        array[i++] = n % 10 + '0';
        n /= 10;
    }
    for (int j = i - 1; j >= 0; j--) {
        mx_printchar(array[j]);
    }
}

int main(int argc, char *argv[]) {
    mx_printstr(argv[0]);
    write(1, "\n", 1);
    mx_printint(argc);
    write(1, "\n", 1);
    return 0;
}

