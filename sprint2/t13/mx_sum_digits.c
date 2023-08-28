 int mx_sum_digits(int num) {
    int summ = 0;
    while (1) {
        summ += num % 10;
        if (num < 10 && num > -10) {
            break;
        }
        num /= 10;
    }
    if (summ < 0) {
        return -summ;
    }
    return summ;
}

 
