char *mx_strncpy(char *dst, const char *src, int len) {
    if (dst == 0 && src == 0) return 0;
    char* beg = dst;
    while (*src && len--) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return beg;
}


