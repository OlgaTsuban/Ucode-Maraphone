int mx_factorial_iter(int n) {
    int res = 1;
    if (n == 0) {
        return 1;
    }
    if (n >= 1 && n <= 12) {
        for (int i = 1; i <= n; i++) {
            res *= i;
        }
        return res;
    }
    return 0;
}
 

