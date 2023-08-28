#include <stdlib.h>

void mx_strdel(char **str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcpy(char *dst, const char *src);
char *mx_strcat(char *s1, const char *s2);

char *mx_concat_words(char **words) {
    if (words == NULL || words[0] == NULL) return NULL;
    char *t = "";
    int i;
    for (i = 1; words[i] != NULL; ++i) {
        t = mx_strjoin(t, words[i - 1]);
        t = mx_strjoin(t, " ");
        mx_strdel(words + i - 1);
    }
    if (words[i] == NULL) {
        t = mx_strjoin(t, words[i - 1]);
        mx_strdel(words + i - 1);
    }
    return t;
}


