#ifndef HEADER_H
#define HEADER_H

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
 
struct stolb {
 wchar_t *arr;
 int len, first, last;
};
 
void start_screensaver(WINDOW *win, int argc, char *flag);
wchar_t get_japan();
void print_string();
int mx_strcmp(const char *s1, const char *s2);
void mx_printerr(const char *s);
int mx_strlen(const char *s);

#endif

