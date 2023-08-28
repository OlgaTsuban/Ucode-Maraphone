#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);

char *mx_strtrim(const char *str) {
    if (str == NULL) return NULL;
    int beg = 0;
    int end = mx_strlen(str) - 1;
    char *s = NULL;
    int size;
    while (mx_isspace(str[beg]))
        beg++;
    while (mx_isspace(str[end]))
        end--;
    size = end - beg + 1;
    s = mx_strnew(size);
    for (int i = 0; i < size; i++) {
        s[i] = str[beg];
        beg++;
    }
    return s;
}


