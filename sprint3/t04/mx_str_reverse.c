int mx_strlen(char* s);
void mx_swap_char(char *s1, char *s2);

void mx_srt_reverse(char *s) {
    int i = 0;
    int b = mx_strlen(s);
    while (i < b / 2) {
        mx_swap_char(&s[i], &s[b - i - 1]);
        i++;
    }
}

 
