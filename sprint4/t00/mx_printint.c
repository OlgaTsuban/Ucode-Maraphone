#include <unistd.h>

void mx_printint(int n) {
    char ar[50];
    int i = 0;
    if (n == 0) write(1, "0", 1);
    if (n == -2147483648) write(1, "-2147483648", 11);
    if (n < 0 && n != -2147483648) {
        n *= -1;
        write(1, "-", 1);
    }
    while (n != 0 && n != -2147483648) {
        ar[i++] = n % 10 + '0';
        n /= 10;
    }
    for (int k = i - 1; k >= 0; k--) {
        write(1, &ar[k], 1);
    }
}

 
