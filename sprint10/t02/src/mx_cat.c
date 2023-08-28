#include "../inc/header.h"

int main(int argc, char *argv[]) {
    char symbol;
    int col;
    
    if (argc == 1) {
        while (read(0, &symbol, 1)) {
            write(1, &symbol, 1);
        }
    }
    for(int i = 1; i < argc; i++) {
        col = open(argv[i], O_RDONLY);
        if (col < 0) {
            write(2, "mx_cat: ", 8);
            write(2, argv[i], mx_strlen(argv[i]));
            write(2, ": No such file or directory\n", 28);
        }
        else {
            while (read(col, &symbol, 1)) {
                write(1, &symbol, 1);
            }
        }
        close(col);
    }
    exit(0);
}
