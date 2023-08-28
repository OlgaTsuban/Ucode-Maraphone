#include "file_to_str.h"

char *mx_strcpy(char *dst, const char *src) {
   int count = 0;
   while (1) {
       dst[count] = src[count];
       if (src[count] == '\0') {
           break;
       }
       count++;
   }
   return dst;
}


