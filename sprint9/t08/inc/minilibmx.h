#ifndef MINILIBMX_H
#define MINILIBMX_H

#define NOT_NUM -666666

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

bool mx_isdigit(int c);

int mx_strlen(const char* s);

bool mx_isspace(char c);

void mx_printerr(const char *s);

int mx_atoi(const char *str);

int mx_strcmp(const char *s1, const char *s2);

void mx_printchar(char c);

void mx_printint(int n);


#endif
