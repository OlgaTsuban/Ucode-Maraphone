#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printerr(" [source_file] [target_file]\n");
        return -1;
    }
    int search ;
    search = open(argv[1], O_RDONLY);
    if (search < 0) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        return -1;
    }
    char sign;
    int result = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
    while (read(search, &sign, 1)) {
        write(result, &sign, 1);
    }
    close(search);
    close(result);
    return 0;
}


