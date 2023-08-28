#include "../inc/header.h"

void start_screensaver(WINDOW *win, int argc, char *flag) {
    int speed = 30;
    int r, c;
    
    getmaxyx(win, c, r);
    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
     init_pair(4, COLOR_YELLOW, COLOR_BLACK);
     init_pair(5, COLOR_CYAN, COLOR_BLACK);
     init_pair(6, COLOR_BLUE, COLOR_BLACK);
     init_pair(7, COLOR_RED, COLOR_BLACK);

    curs_set(false);
    noecho();
    
    struct stolb *mass = malloc(sizeof(struct stolb) * r);

    for (int i = 0; i < r; i++) {
        mass[i].arr = malloc(sizeof(wchar_t) * c);


        for (int j = 0; j < c; j++)
            mass[i].arr[j] = get_japan();
        mass[i].len = rand() % c;
        mass[i].first = 0 - mass[i].len - mass[i].len;
        mass[i].last = 0 - mass[i].len;
    }
    wbkgd(win, COLOR_PAIR(2));
    int color = 2;
    

    wclear(win);

    if (argc != 2 || (argc == 2 && mx_strcmp(flag, "-s") != 0)) {
        print_string(win);
    }
    
    
    while(true) {
        wtimeout(win, speed);
        
        if (getch() == 'q') {
            break;
        }
        
        if(getch() == '+') {
            if (speed > 0) {
                speed -= 10;
            }
            
        }
        if(getch() == '-') {
            if (speed < 200) {
                speed += 10;
            }
        }
        if(getch() == 'a') {
            int temp = color;
            while(color == temp) {
                color = rand() % 7 + 1;
            }
        }
        wclear(win);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j >= mass[i].first && j <= mass[i].last) {
                    if (j == mass[i].last) {
                        attroff(COLOR_PAIR(color));
                        attron(COLOR_PAIR(1));
                    }
                    
                    mvprintw(j, i+i, "%lc", mass[i].arr[j]);
                    
                    if (j == mass[i].last) {
                        attroff(COLOR_PAIR(1));
                        attron(COLOR_PAIR(color));
                    }
                    
                    if (j == mass[i].first) {
                        mass[i].arr[j] = get_japan();
                    }
                    if (j == mass[i].last) {
                        mass[i].arr[j] = get_japan();
                    }
                    
                }
            }
            mass[i].first++;
            mass[i].last++;
            
            if (mass[i].first > c) {
                mass[i].len = rand() % c;
                mass[i].first = 0 - mass[i].len - mass[i].len;
                mass[i].last = 0 - mass[i].len;
            }
        }
        refresh();
    }



    for(int i = 0; i < c; i++) {
        free(mass[i].arr);
    }
    free(mass);
}


wchar_t get_japan() {

    wchar_t alphabet[] = {L"゠ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタ"
                         "ダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミ"
                         "ムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺ・ーヽヾヿ"};
    return alphabet[rand() % 96];
}

int mx_strcmp(const char *s1, const char *s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0' && *s2 == '\0') {
            return 0;
        }
        s1++;
        s2++;
    }
    return (int)*s1 - *s2;
}



int mx_strlen(const char *s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}


void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}


void print_string(WINDOW* win) {
    
    char text1[] = "Wake up , Neo..";
    char text2[] = "The Matrix has you..";
    char text3[] = "Follow the white rabbit";
    char text4[] = "Knock, knock, Neo";
    
    
    for (int i = 0; i < 15; i++) {
        mvwaddch(win, 2, 2 + i, text1[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    
    
    for (int i = 0; i < 20; i++) {
        mvwaddch(win, 2, 2 + i, text2[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    for (int i = 0; i < 23; i++) {
        mvwaddch(win, 2, 2 + i, text3[i]);
        refresh();
        usleep(200000);
    }
    wclear(win);
    usleep(100000);
    for (int i = 0; i < 17; i++) {
        mvwaddch(win, 2, 2 + i, text4[i]);
        refresh();
        usleep(200000);
    }
}
