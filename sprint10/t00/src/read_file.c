#include "../inc/header.h"
int main(int argc, char *argv[]) {
    if (argc < 2) {
            write(2, "usage: ./read_file [file_path]\n", 31);
            return -1;
        }
    ssize_t try;
        int fileopen = open(argv[1], O_RDONLY);
        if(fileopen < 0) {
            write(2, "error\n", 6);
            return -1;
        }
        char text;
        while ((try = read(fileopen, &text, 1) > 0)) {
            write(1, &text, 1);
            if(try < 0) {
                write(2, "error\n", 6);
                return -1;
            }
        }
        close(fileopen);
    return 0;
}


