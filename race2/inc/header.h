#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
 
typedef
struct sMap{
    int w;
    int h;
    int **dots;
}    Map;

bool mx_get_path(Map *source, Map **dist, int x, int y, int n);
char **mx_parse_text(char *text);
char *mx_str_append(char *str, char symbol);
int mx_strlen(char *s);
char *mx_strnew(int size);
void mx_wave_func(Map **map, int x, int y, int n);
Map *mx_build_map(char **mapText);
int mx_get_max_distance(Map *map);
char *mx_parse_map(Map *map, int startX, int startY, int endX, int endY);
void mx_printchar(char c);
void mx_printerr(char *str);
void mx_printerr_c(char *str);
void mx_printint(int n);
char *mx_open_file(char *path);
int mx_atoi(const char *str);
bool mx_isdigit(char c);
bool mx_isspace(char c);
void mx_printstr(const char *s);
int mx_get_dot_distance(Map *map, int x, int y);
void mx_write_file(char *path, char *data);

#endif

