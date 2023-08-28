void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printint(int n);

int main (int argc, char *argv[]) {
    mx_printstr(*argv);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
    return 0;
}
