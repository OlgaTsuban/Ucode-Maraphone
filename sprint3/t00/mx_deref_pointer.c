void mx_deref_pointer(char ******str) {
    char *m = "Follow the white rabbit!";
    char **mm;
    char ***mmm;
    char ****mmmm;
    char *****mmmmm;
    mm = &m;
    mmm = &mm;
    mmmm = &mmm;
    mmmmm = &mmmm;
    str = &mmmmm;
 }
 

