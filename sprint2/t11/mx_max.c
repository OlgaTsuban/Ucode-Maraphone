 int mx_max(int a, int b, int c) {
    if (b > a && b > c) {
        return b;
    }
    if (a > c) {
        return a;
    }
    else {
        return c;
    }
}

 
