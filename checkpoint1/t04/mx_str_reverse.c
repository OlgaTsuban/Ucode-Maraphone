 void mx_str_reverse(char *s) {
    int i = 0, account = 0;
    while (s[account] != '\0') {
        account++;
    }
    int b = account;
    while (i < b / 2) {
        char a = s[i];
        s[i] = s[b - i - 1];
        s[b - i -1] = a;
        i++;
    }
}

 
