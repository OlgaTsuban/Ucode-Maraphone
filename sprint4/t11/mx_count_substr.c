char *mx_strchr(const char *s, int c);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    const char *need = sub;
    int total = 0;
    const char *ptr = str;
    while ( (ptr = mx_strstr(p,need)) != 0 ) {
            ptr += mx_strlen(need);
            total++;
    }
    return total;
}


