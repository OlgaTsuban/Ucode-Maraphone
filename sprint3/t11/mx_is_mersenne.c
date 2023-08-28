#include <stdbool.h>

double mx_pow(double n, unsigned int pow);
bool mx_is_prime(int num);

bool mx_is_mersenne(int n) {
    int prm = 0;
    if (mx_is_prime(n) == true) {
        for (int i = 2; i <= n; i++) {
            prm = mx_pow(2, i) - 1;
            if (prm == n) {
                return true;
            }
        }
    }
    return false;
}
 

