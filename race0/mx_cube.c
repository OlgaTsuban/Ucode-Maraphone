#include <unistd.h>
void mx_printchar(char c);

void mx_cube(int n) {
    int i = 0, k = 0, p = 0, w = 0, o = 0;
    if (n <= 1) return;
    while (i <= 2 * n + 2 + n / 2) {
            if (i < n / 2 + 1) {
                mx_printchar(' ');
                i++;
                continue;
        }
        if (i == n / 2 + 1 || i == n * 2 + 2 + n / 2) {
            mx_printchar('+');
            i++;
            continue;
        }
        else mx_printchar('-');
        i++;
    }
    write(1, "\n",1);
    while(k < n / 2) {
        int j = 0;
        while (j <= 2 * n + 2 + n / 2) {
            if (j == n / 2 - k || j == 2 * n - k + 1 + n / 2) {
                mx_printchar('/');
                j++;
                continue;
            }
            else  if (j == 2 * n + 2 + n / 2) {
                mx_printchar('|');
            }
            else mx_printchar(' ');
            j++;
        }
        write(1, "\n", 1);
        k++;
    }
    int e = 0;
    while (e <= 2 * n + 2 + n / 2) {
        if (e == 0 || e == 2 * n + 1) {
            mx_printchar('+');
            e++;
            continue;
        }else if (e > 2 * n + 1 && e < 2 * n + 2 + n / 2) mx_printchar(' ');
         else if (e == 2 * n + 2 + n / 2) mx_printchar('|');
          else mx_printchar('-');
        e++;
    }
    write(1, "\n", 1);
    int b = 0;
    if (n % 2 == 0)  b = n / 2 -1;
    else b = n / 2;
        while (p < b) {
            int y= 0;
            while (y <= 2 * n + 2 + n / 2) {
                if (y == 0 || y == 2 * n + 1 || y == 2 * n + 2 + n / 2) {
                    mx_printchar('|');
                    y++;
                    continue;
                }
                else mx_printchar(' ');
                y++;
            }
            write(1, "\n", 1);
            p++;
        }
    while (w <= 2 * n + 2 + n / 2) {
        if (w == 0 || w == 2 * n + 1) {
            mx_printchar('|');
            w++;
            continue;
        } if (w == 2 * n + 2 + n / 2) mx_printchar('+');
        else mx_printchar(' ');
        w++;
    }
    write(1, "\n", 1);
    while (o < n / 2) {
        int h = 0, q = n / 2;
        while (h < 2 * n + 2 + n / 2){
            if (h == 0 || h == 2 * n + 1 - k + n / 2) {
                mx_printchar('|');
                h++;
            } if (h == 2 * n + 2 - o + n / 2 - 1) {
                mx_printchar('/');
                q--;
                break;
            } else mx_printchar(' ');
            h++;
        }
        write(1, "\n", 1);
        o++;
    }
    int t = 0;
    while (t < 2 * n + 2) {
        if (t == 0 || t == n * 2 + 1) {
            mx_printchar('+');
            t++;
            continue;
        }
        else mx_printchar('-');
        t++;
    }
    write(1, "\n", 1);
}
 

