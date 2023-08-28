#include "nbr_to_hex.h"


char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr > 4294967295 || nbr < 0) return 0;
    char *p = NULL;
    if (nbr == 0) {
        p = mx_strnew(1);
        p[0] = '0';
        return p;
    }
    unsigned int q = nbr;
    int r, size = 0, j = 0;
    int t = nbr;
    while (t != 0){
        size++;
        t /= 16;
    }
    char *hex  = (char *)malloc(size);
    while (q != 0){
        r = q % 16;
        if (r < 10)
            hex[j] = 48 + r;
        else
            hex[j] = 87 + r;
        j++;
        q /= 16;
    }
    j--;
    for (int i = 0; i < j; i++, j--){
        char tmp = hex[i];
        hex[i] = hex[j];
        hex[j] = tmp;
    }
    return hex;
}



