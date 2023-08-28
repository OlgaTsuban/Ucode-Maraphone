#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_narcissistic(int num) {
    int or, digit = 0, sum = 0;
    or = num;
    if (or < 0) {
        return false;
    }
    while (num != 0) {
        digit++;
        num = num / 10;
    }
    num = or;
    while (num != 0) {
        int rem = num % 10;
        sum = sum + mx_pow(rem, digit);
        num = num / 10;
    }
    if (sum == or) {
        return true;
    } else return false;
}

 
