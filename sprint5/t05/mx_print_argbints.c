#include <stdbool.h>

bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printint(int n);
bool mx_isspace(char c);
int mx_atoi(const char *str);

 int main(int argc, char *argv[]) {
     for (int i = 0; (++i) < argc; mx_printchar('\n')) {
         for (int j = 31; j >= 0; j--){
             mx_printchar(((mx_atoi(argv[i]) >> j) & 1) + '0');
         }
     }
 }


