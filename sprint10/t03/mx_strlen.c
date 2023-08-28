#include "file_to_str.h"
int mx_strlen(const char* s) {
   int account = 0;
   while (*s != '\0'){
       account++;
       s++;
   }
   return account;
}


