int mx_atoi(const char *str) {
   int sum = 0;
   int num = 1;
   for (int i = 0; str[i] != '\0'; i++) {
       if (str[i] == '-') {
           num = -1;
           i++;
       }
       if (str[i] == '+') i++;
       if (str[i] >= '0' && str[i] <= '9') {
           sum = sum * 10 + (str[i] - '0');
       }
       else {
           break;
       }
   }
   return sum * num;
}

