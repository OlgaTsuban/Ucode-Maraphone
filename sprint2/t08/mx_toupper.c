int mx_toupper(int c) {
    if (c >= 65 && c <= 90) {
        return c;
    }
    if (c >= 97 && c <= 122) {
        return c-32;
    }
}
 

