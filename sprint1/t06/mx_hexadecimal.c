#include <unistd.h>

void mx_printchar(char c);
 void mx_hexadecimal(void) {
        for(int i = 0;i<16;i++) {
            if(i < 10) mx_printchar(i +'0');
            else mx_printchar(i + 55);
        }
     write(1, "\n", 1);
    }


