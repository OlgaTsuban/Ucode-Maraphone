int mx_gcd(int a, int b);

int mx_lcm(int a, int b) {
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    if ((a == 0 && b ==0) || a > 2147483647 / b) {
        return 0;
    }
    if (mx_gcd(a, b) == 0) {
        return 0;
    }
    int res = (a * b) / mx_gcd(a, b);
    return res;
}



