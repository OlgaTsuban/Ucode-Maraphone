#include<stdio.h>
#include<stdlib.h>
char *mx_strnew(const int size) {
  if (size <= 0) {
    return NULL;
  }
  char *ptr = NULL;
  ptr = (char*)malloc(size + 1);
  for (int i = 0;  i < size + 1; i++) {
    ptr[i] = '\0';
  }
  return ptr;
}
char *mx_nbr_to_hex(unsigned long nbr) {
  int  j = 0;
  char *hex = mx_strnew(100);
  unsigned long add, numb = nbr;
  while (numb != 0) {
    add = numb % 16;
    if (add < 10) {
      hex[j] = 48 + add;
    }
    else {
      hex[j] = 87 + add;
    }
    j++;
    numb /= 16;
  }
  char *ptr = mx_strnew(j);
  for (int i = 0; j >= 0; i++) {
    ptr[i] = hex[j - 1];
    j--;
  }
  return ptr;
}



