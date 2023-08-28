void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

int main(int count, char **args) {
    for (int i = 1; i < count; ++i) {
        mx_printstr(args[i]);
        mx_printchar('\n');
    }
    return 0;
}
