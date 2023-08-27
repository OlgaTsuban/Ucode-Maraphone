#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

void mx_printchar(char c) {
    write(1, &c, 1);
}

bool mx_isdigit( int c) {
    if (c >= 48 && c <= 57) {
        return 1;
    }
    else {
        return 0;
    }
}

bool mx_isspace(char c) {
    if (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
        return 1;
    }
    else {
        return 0;
    }
}

int mx_strlen(const char* s) {
   int account = 0;
   while (*s != '\0'){
       account++;
       s++;
   }
   return account;
}

void mx_swap_char(char *s1, char *s2) {
    char s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void mx_printerr(const char *s) {
    int j = 0;
    while (s[j] != '\0') {
        j++;
    }
    write(2, s, j);
}

void mx_printint(int n) {
    char ar[50];
    int i = 0;
    if (n == 0) write(1, "0", 1);
    if (n == -2147483648) write(1, "-2147483648", 11);
    if (n < 0 && n != -2147483648) {
        n *= -1;
        write(1, "-", 1);
    }
    while (n != 0 && n != -2147483648) {
        ar[i++] = n % 10 + '0';
        n /= 10;
    }
    for (int k = i - 1; k >= 0; k--) {
        write(1, &ar[k], 1);
    }
}

void mx_printstr(const char *s) {
    int account = 0;
    while (s[account] != '\0') {
        account++;
    }
    write(1, s, account);
}

void mx_str_reverse(char *s) {
    int len = mx_strlen(s) - 1;
    
    if (s)
        for (int i = 0; i <= len / 2; i++)
            mx_swap_char(&s[i], &s[len - i]);
}

char *mx_strcpy(char *dst, const char *src) {
    int i = 0;
    
    while (src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}

char *mx_strnew(const int size) {
    char *s = (char *)malloc(size + 1);
    if( size < 0) return 0;
    if (s == NULL) return s;
    for (int i = 0; i <= size ; i++) {
        s[i] = '\0';
    }
    return s;
}

int mx_pow(int n, unsigned int pow) {
    int result = 1;
    for (unsigned int i = 0; i < pow; i++) {
        result = result * n;
    }
    return result;
}

static int number_length(int number) {
    int length = 0;

    while (number) {
        number /= 10;
        length++;
    }
    return length;
}

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int size = 0;
    int count_left = 0;
    int count_right = 0;

    for (; *str;) {
        size++;
        str++;
    }

    str -= size;

    for (; *str && mx_isspace(*str); count_left++) {
        str++;
    }

    str -= count_left;
    
    for (int i = size - 1; i >= count_left; i--) {
        if (!mx_isspace(str[i])) {
            break;
        }
        
        count_right++;
    }
    
    char *array = mx_strnew(size - count_left - count_right);
    
    for (int i = count_left, j = 0; i <= size - 1 - count_right; i++, j++) {
        array[j] = str[i];
    }
        
    return array;
}

int mx_atoi(const char *str) {
  int s = 0;
  int p = 0;
  int digit = 0;
    for (unsigned int i = 0; str[i]; ++i) {
           if (!mx_isspace(str[i])) {
               if (mx_isdigit(str[i])) {
                   digit = digit * 10 + (str[i] - '0');
               }
               else if (mx_isspace(str[i + 1]) && str[i] == '-') {
                   return 0;
               }
               else {
                   if (str[i] == '-') {
                       if (!str[i + 1]) {
                           return 0;
                       }
                       else if (s == 0 && p == 0) {
                           s = 1;
                       }
                       else {
                           return 0;
                       }
                   }
                   else if (str[i] == '+') {
                       if (!str[i + 1]) {
                           return 0;
                       }
                       else if (p == 0 && s == 0) {
                           p = 1;
                       }
                       else {
                           return 0;
                       }
                   }
                   else {
                       return 0;
                   }
               }
           }
       }
       if (s == 1) {
          return -digit;
       }
       else {
           return digit;
       }
   }

char *mx_itoa(int number) {
    int length = number_length(number);
    int tmp = number;
    char *result = NULL;

    result = mx_strnew(length);
    if (number == 0)
        return mx_strcpy(result, "0");
    if (number == -2147483648)
        return mx_strcpy(result, "-2147483648");
    tmp = number;
    for (int i = 0; i < length; i++) {
        if (tmp < 0) {
            result[length] = '-';
            tmp = -tmp;
        }
        result[i] = (tmp % 10) + '0';
        tmp /= 10;
    }
    mx_str_reverse(result);
    return result;
}

void mx_operations(char *operand1, char *operation, char *operand2, char *result) {
    if (*operation == '?') {
        mx_operations(operand1, "+", operand2, result);
        mx_operations(operand1, "-", operand2, result);
        mx_operations(operand1, "*", operand2, result);
        mx_operations(operand1, "/", operand2, result);
        return;
    }

    int operand1_len = mx_strlen(operand1), operand2_len = mx_strlen(operand2), res_len = mx_strlen(result);
    bool operand1_negative = false, operand2_negative = false, result_negative = false;

    if (operand1[0] == '-') {
        operand1_negative = true;
        operand1++;
        operand1_len--;
    }

    if (operand2[0] == '-') {
        operand2_negative = true;
        operand2++;
        operand2_len--;
    }

    if (result[0] == '-') {
        result_negative = true;
        result++;
        res_len--;
    }

    int operand1_integer = mx_atoi(operand1), operand2_integer = mx_atoi(operand2), result_integer = mx_atoi(result);

    for (long long i = 0; i < mx_pow(10, operand1_len); i++) {
        if (operand1_integer > 0) {
            i = operand1_integer;
        }
        char *iqueue = mx_itoa(i);
        int ilen = mx_strlen(iqueue);
        bool iiscorrect = true;

        for (int j = 0; j < operand1_len - ilen; j++) {
            if (mx_isdigit(operand1[j]) && operand1[j] != '0') {
                iiscorrect = false;
                break;
            }
        }

        for (int j = operand1_len - ilen, k = 0; j < operand1_len; j++, k++) {
            if (operand1[j] != '?' && operand1[j] != iqueue[k]) {
                iiscorrect = false;
                break;
            }
        }

        free(iqueue); iqueue = NULL;
        if (!iiscorrect)
            continue;

        for (long long j = 0; j < mx_pow(10, operand2_len); j++) {
            if (operand2_integer > 0) {
                j = operand2_integer;
            }
            char *jqueue = mx_itoa(j);
            int jlen = mx_strlen(jqueue);
            bool jiscorrect = true;

            for (int p = 0; p < operand2_len - jlen; p++) {
                if (mx_isdigit(operand2[p]) && operand2[p] != '0') {
                    jiscorrect = false;
                    break;
                }
            }

            for (int p = operand2_len - jlen, jqueue_i = 0; p < operand2_len; p++, jqueue_i++) {
                if (operand2[p] != '?' && operand2[p] != jqueue[jqueue_i]) {
                    jiscorrect = false;
                    break;
                }
            }

            free(jqueue); jqueue = NULL;
            if (!jiscorrect)
                continue;
            
            for (long long k = 0; k < mx_pow(10, res_len); k++) {
                if (result_integer > 0) {
                    k = result_integer;
                }
                char *kqueue = mx_itoa(k);
                int kqueue_len = mx_strlen(kqueue);
                bool isCorrectK = true;

                for (int n = 0; n < res_len - kqueue_len; n++) {
                    if (mx_isdigit(result[n]) && result[n] != '0') {
                        isCorrectK = false;
                        break;
                    }
                }

                for (int n = res_len - kqueue_len, kqueue_i = 0; n < res_len; n++, kqueue_i++) {
                    if (result[n] != '?' && result[n] != kqueue[kqueue_i]) {
                        isCorrectK = false;
                        break;
                    }
                }

                free(kqueue); kqueue = NULL;
                if (!isCorrectK)
                    continue;

                if (operand1_negative)
                    i *= -1;
                if (operand2_negative)
                    j *= -1;
                if (result_negative)
                    k *= -1;

                if (*operation == '+') {
                    if (i + j == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-') {
                        if (i - j == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*') {
                        if (i * j == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/') {
                    if (j != 0 && i / j == k) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                
                if (operand1_negative)
                    i *= -1;
                if (operand2_negative)
                    j *= -1;
                if (result_negative)
                    k *= -1;
                if (result_integer > 0)
                    break;
            }
            if (operand2_integer > 0)
                break;
        }
        if (operand1_integer > 0)
            break;
    }

    if (operand1_negative)
        operand1--;
    if (operand2_negative)
        operand2--;
    if (result_negative)
        result--;
}

void mx_parser(char *argv[], char *operand1, char *operation, char *operand2, char *result) {

    if (mx_strlen(operand1) <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[1]);
        mx_printerr("\n");
        exit(-1);
    }

    if (mx_strlen(operation) != 1) {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }

    if (mx_strlen(operand2) <= 0) {
        mx_printerr("Invalid operand: ");
        mx_printerr(argv[3]);
        mx_printerr("\n");
        exit(-1);
    }

    if (mx_strlen(result) <= 0) {
        mx_printerr("Invalid result: ");
        mx_printerr(argv[4]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < mx_strlen(operand1); i++) {
        if (i == 0 && operand1[i] == '-') {
            continue;
        }
        if (operand1[i] != '?' && !mx_isdigit(operand1[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[1]);
            mx_printerr("\n");
            exit(-1);
        }
    }


    if (*operation != '?' && *operation != '+' && *operation != '-' && *operation != '*' && *operation != '/') {
        mx_printerr("Invalid operation: ");
        mx_printerr(argv[2]);
        mx_printerr("\n");
        exit(-1);
    }

    for (int i = 0; i < mx_strlen(operand2) ; i++) {
        if (i == 0 && operand2[i] == '-') {
            continue;
        }
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[3]);
            mx_printerr("\n");
            exit(-1);
        }
    }

    for (int i = 0; i < mx_strlen(result) ; i++) {
        if (i == 0 && result[i] == '-') {
            continue;
        }
        if (result[i] != '?' && !mx_isdigit(result[i])) {
            mx_printerr("Invalid operand: ");
            mx_printerr(argv[4]);
            mx_printerr("\n");
            exit(-1);
        }
    }
}

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    while (src[i] && i != len) {
        dst[i] = src[i];
        i++;
    }
    return dst;
}

char *mx_strndup(const char *s1, int n) {
    char *duplicate = NULL;
    int length = mx_strlen(s1);

    if (n < length)
        length = n;
    duplicate = mx_strnew(length);
    mx_strncpy(duplicate, s1, length);
    return duplicate;
}
