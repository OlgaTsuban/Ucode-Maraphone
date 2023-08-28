#include <stdbool.h>

bool mx_is_prime(int num) {
    if (num == 2) {
        return true;
    }
    if (num == 0 || num == 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
            break;
        }
    }
    return true;
}
 

