void mx_printchar(char c);
int mx_strlen(const char *s);
char *mx_strchr(const char *s, int c);
void mx_printstr(const char *s);

int main (int argc ,char **argv) {
    argc++;
    char *p = argv[0];
    int count = 0;
    int i = 0;
    while (p[i] != '\0') {
        if (p[i] == '/') {
            count++;
        }
        i++;
    }
    for (int i = 0; i < count; i++) {
        p = mx_strchr(p, '/');
        if (p[0] == '/') {
            p = mx_strchr(p, p[1]);
        }
    }
        mx_printstr(p);
        mx_printchar('\n');
    return 0;
}


