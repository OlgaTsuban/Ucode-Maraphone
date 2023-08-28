int mx_strlen(const char* s) {
   int account = 0;
   while (*s != '\0'){
       account++;
       s++;
   }
   return account;
}

