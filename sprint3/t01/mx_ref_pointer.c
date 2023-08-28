 void mx_ref_pointer(int i, int ******ptr) {
    int *m;
    int **mm;
    int ***mmm;
    int ****mmmm;
    int *****mmmmm;
    m = &i;
    mm = &m;
    mmm = &mm;
    mmmm = &mmm;
    mmmmm = &mmmm;
    ptr = &mmmmm;
}
 

