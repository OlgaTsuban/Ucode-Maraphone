#include <stdbool.h>

int mx_strlen(const char *s);
void mx_printchar(char c);
int mx_atoi(const char *str);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printint(int n);

int main(int argc, char *argv[]) {
     if (argc != 3)
         return 0;
     int a = mx_atoi(argv[1]), b = mx_atoi(argv[2]);
     if (a > 9 || a < 0 || b > 10 || b < 0)
                 return 0;
     if (b < a) {
         int y = b;
         b = a;
         a = y;
     }
    for (int i = a; i <= b;i++) {
         for (int j = a; j <= b; j++) {
             mx_printint(i * j);
             if (j!= b)
                 mx_printchar('\t');
         }
         mx_printchar('\n');
     }
     return 0;
}


