#include <stdlib.h>
#include <stdio.h>

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

int mx_strlen(const char* s) {
   int account = 0;
   while (*s != '\0'){
       account++;
       s++;
   }
   return account;
}

char *mx_strnew(const int size) {
    char *s = (char *)malloc(size + 1);
    if( size < 0) return 0;
    if (s == NULL) return s;
    for (int i = 0; i <= size ; i++) {
        s[i] = '\0';
    }
    return s;
}

char *mx_strdup(const char *str) {
    int size = mx_strlen(str);
    char *dup = mx_strnew(size);
    if( dup == 0) return NULL;
    mx_strcpy(dup, str);
    return dup;
}


