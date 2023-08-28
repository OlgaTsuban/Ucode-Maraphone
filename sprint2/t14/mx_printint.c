void mx_printchar(char c);

void mx_printint(int n) {
    int j = 0;
    int x = n;
    while (x != 0) {
        x /= 10;
        j++;
    }
    int myNumbers[j];
    for (int i = 0; i < j; i++) {
        myNumbers[i] = n % 10;
        n /= 10;
    }
    for (int loop = j - 1; loop >= 0; loop--) {
        mx_printchar(myNumbers[loop] + '0');
    }
}
 
 
