int mx_strncmp(const char *s1, const char *s2, int n) {
    while (n--) {
        if (*s1 != *s2) {
            break;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

