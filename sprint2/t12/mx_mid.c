int mx_mid(int a, int b, int c) {
        if (a > b) {
            if (b > c) return b;
            if (c > a) return a;
            return c;
        }
        if (b < c) return b;
        if (c < a) return a;
        return c;
}

 
