#include "nbr_to_hex.h"

char *mx_strnew(const int size) {
    char *s = (char *)malloc(size + 1);
    if( size < 0) return 0;
    if (s == NULL) return s;
    for (int i = 0; i <= size ; i++) {
        s[i] = '\0';
    }
    return s;
}
char *mx_nbr_to_hex(unsigned long nbr) {
    if(nbr == 0) {
          char * res = mx_strnew(1);
          res[0] = '0';
          return res;
      }
  
  unsigned long start = nbr;
  int number_of_digits = 0;
  
  while(start > 0) {
    start /= 16;
    number_of_digits++;
  }
  char *hex_number = mx_strnew(number_of_digits);
  
  int counter = number_of_digits - 1;
  while(nbr > 0) {
    int buff = nbr % 16;
    switch(buff) {
      case 10:
        hex_number[counter] = 'a';
        break;
      case 11:
        hex_number[counter] = 'b';
        break;
      case 12:
        hex_number[counter] = 'c';
        break;
      case 13:
        hex_number[counter] = 'd';
        break;
      case 14:
        hex_number[counter] = 'e';
        break;
      case 15:
        hex_number[counter] = 'f';
        break;
      default:
        hex_number[counter] = buff + 48;
        break;
    }
    nbr /= 16;
    counter--;
  }
  return hex_number;
}



