#include <stdlib.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strtrim(const char *str);
bool mx_isspace(char c);
void mx_strdel(char **str);
int mx_strlen(const char* s);

char *mx_del_extra_whitespaces(const char *str) {
    if (str == NULL) return NULL;
    int j = 0;
    char *tr = mx_strtrim(str);
    int y = mx_strlen(tr);
    char *del = mx_strnew(y);
    if (del == NULL) return NULL;
    for (int i = 0; tr[i] != '\0'; i++) {
        if (mx_isspace(tr[i]))
            for (del[j++] = ' '; mx_isspace(tr[i]); i++);
                del[j++] = tr[i];
    }
    char *out = mx_strnew(mx_strlen(del));
    if (out == NULL) return NULL;
    mx_strncpy(out, del,y);
    mx_strdel(&tr);
    mx_strdel(&del);
    return out;
}



