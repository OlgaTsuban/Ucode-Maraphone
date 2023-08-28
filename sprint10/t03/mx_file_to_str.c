#include "file_to_str.h"

char *mx_file_to_str(const char *filename) {
    if (!filename) return NULL;
    int file = open(filename, O_RDONLY);
    if (file < 0) return NULL;
    int col = 0;
    char c;
    while (read(file, &c, 1) != 0) {
        col++;
    }
    close(file);
    file = open(filename, O_RDONLY);
    char *text = mx_strnew(col);
    for (int i = 0; read(file, &c, 1); i++) {
            text[i] = c;
        }
    close(file);
    return text;
}



