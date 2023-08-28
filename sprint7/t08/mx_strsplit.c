#include <stdlib.h>
int mx_count_words(const char *str, char delimiter);
void mx_strdel(char **str);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);

char **mx_strsplit(char const *s, char c) {
    int count = mx_count_words(s, c);
    int j = 0;
    char **res = (char**)malloc(8 * count);
    for (int i = 0; i < count; i++) {
        int len = 0;
        int start = 0;
        for (; s[j]; j++) {
            if (s[j] != c) {
                len += 1;
                if (start == 0) {
                    start = j;
                }
            }
            else if (s[j] == c && len)
                break;
        }
        char* news = mx_strnew(len);
        for (int k = 0, m = start; m < j; k++, m++) {
            news[k] = s[m];
        }
        res[i] = news;
    }
    res[count] = NULL;
    return res;
}



