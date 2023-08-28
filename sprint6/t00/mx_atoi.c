#include <stdbool.h>
bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
  int s = 0;
  int p = 0;
  int digit = 0;
    for (unsigned int i = 0; str[i]; ++i) {
           if (!mx_isspace(str[i])) {
               if (mx_isdigit(str[i])) {
                   digit = digit * 10 + (str[i] - '0');
               }
               else if (mx_isspace(str[i + 1]) && str[i] == '-') {
                   return 0;
               }
               else {
                   if (str[i] == '-') {
                       if (!str[i + 1]) {
                           return 0;
                       }
                       else if (s == 0 && p == 0) {
                           s = 1;
                       }
                       else {
                           return 0;
                       }
                   }
                   else if (str[i] == '+') {
                       if (!str[i + 1]) {
                           return 0;
                       }
                       else if (p == 0 && s == 0) {
                           p = 1;
                       }
                       else {
                           return 0;
                       }
                   }
                   else {
                       return 0;
                   }
               }
           }
       }
       if (s == 1) {
          return -digit;
       }
       else {
           return digit;
       }
   }



