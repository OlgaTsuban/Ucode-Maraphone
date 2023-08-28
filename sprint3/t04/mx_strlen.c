int mx_strlen(char* s) {
   int account = 0;
   while (*s != '\0') {
       account++;
       s++;
   }
   return account;
}


