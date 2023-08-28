#include "../inc/header.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "ja_JP.UTF-8");
    if (argc > 2) {
        mx_printerr("usage: ./matrix_rain [-s]\n");
        return 0;
    }
    WINDOW * win;
    
    win = initscr();
    curs_set(0);
    start_screensaver(win, argc, argv[1]);
    delwin(win);
    endwin();
    
    return 0;
}

