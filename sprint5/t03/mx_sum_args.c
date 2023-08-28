#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printint(int n);
int mx_atoi(const char *str);

int norm (char *str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+') {
        ++i;
    }
    while(str[i] != '\0') {
        if (mx_isdigit(str[i])) {
            ++i;
        }
        else {
            return 0;
        }
    }
    return 1;
}
int main(int count, char **args) {
    int sum = 0;
    for (int i = 0; i < count; ++i) {
            if (norm(args[i])) {
                sum += mx_atoi(args[i]);
            }
        }
        mx_printint(sum);
        mx_printchar('\n');
        return 0;
    }


