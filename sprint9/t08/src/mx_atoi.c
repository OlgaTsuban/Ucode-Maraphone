#include "../inc/calculator.h"
 
bool mx_isdigit(int c);
 
bool mx_isspace(char c);
 
int mx_atoi(const char *str)
{
    int z = 0;
    int p = 0;
    int digit = 0;
    for (unsigned int i = 0; str[i]; ++i) {
        if (!mx_isspace(str[i])) {
            if (mx_isdigit(str[i])) {
                digit = digit * 10 + (str[i] - '0');
            }
            else if (mx_isspace(str[i + 1]) && str[i] == '-') {
                return NOT_NUM;
            }
            else {
                if (str[i] == '-') {
                    if (!str[i + 1]) {
                        return NOT_NUM;
                    }
                    else if (z == 0 && p == 0) {
                        z = 1;
                    }
                    else {
                        return NOT_NUM;
                    }
                }
                else if (str[i] == '+') {
                    if (!str[i + 1]) {
                        return NOT_NUM;
                    }
                    else if (p == 0 && z == 0) {
                        p = 1;
                    }
                    else {
                        return NOT_NUM;
                    }
                }
                else {
                    return NOT_NUM;
                }
            }
        }
    }
    if (z == 1) return -digit;
    else {
        return digit;
    }
}
