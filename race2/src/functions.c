#include "../inc/header.h"

int mx_atoi(const char *str)
{
    int n = 0;
    int c = 0;
    if (str[0] == '-')
    {
        c = 1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        n *= 10;
        if (!mx_isdigit(*str) || mx_isspace(*str))
            return 0;
        n += *str++;
        if (*str && (!mx_isdigit(*str) || mx_isspace(*str)))
            return 0;
        n -= '0';
    }
    if (*str != '\0')
        return 0;
    if (c == 1)
        n *= -1;
    return n;
}

Map *mx_build_map(char **mapText){
    Map *map = malloc(sizeof(Map));
    map->w = 0;
    map->h = 0;
    for(char **i = mapText; *i != NULL; i++){
        if(map->w == 0)
            map->w = mx_strlen(*i);
        else
            if(map->w != mx_strlen(*i))
                mx_printerr_c("map error\n");
        map->h++;
    }
    map->dots = malloc(sizeof(int*) * map->h);
    for(int i = 0; i < map->h; i++){
        map->dots[i] = malloc(sizeof(int) * map->w);
        for(int j = 0; j < map->w; j++){
            if(mapText[i][j] == '#')
                map->dots[i][j] = -2;
            if(mapText[i][j] == '.')
                map->dots[i][j] = -1;
        }
    }
    return map;
}
int mx_get_dot_distance(Map *map, int x, int y){
    return map->dots[y][x];
}
int mx_get_max_distance(Map *map){
    int max = -1;
    for(int i = 0; i < map->h; i++)
        for(int j = 0; j < map->w; j++)
            if(map->dots[i][j] > max)
                max = map->dots[i][j];
    return max;
}
bool mx_get_path(Map *source, Map **dist, int x, int y, int n){
    if(*dist == NULL){
        *dist = malloc(sizeof(Map));
        (*dist)->w = source->w;
        (*dist)->h = source->h;
        (*dist)->dots = malloc(sizeof(int*) * source->h);
        for(int i = 0; i < source->h; i++){
            (*dist)->dots[i] = malloc(sizeof(int) * source->w);
            for(int j = 0; j < source->w; j++)
                (*dist)->dots[i][j] = 0;
        }
        n = source->dots[y][x];
        if(source->dots[y][x] < 0)
            return false;
        (*dist)->dots[y][x] = 1;
    }
    
    if(source->dots[y][x] == 0){
        (*dist)->dots[y][x] = 1;
        return true;
    }
    if(x + 1 < source->w)
        if(source->dots[y][x + 1] == n - 1){
            (*dist)->dots[y][x + 1] = 1;
            return mx_get_path(source, dist, x + 1, y, n - 1);
        }
        
    if(x - 1 >= 0)
        if(source->dots[y][x - 1] == n - 1){
            (*dist)->dots[y][x - 1] = 1;
            return mx_get_path(source, dist, x - 1, y, n - 1);
        }
        
    if(y + 1 < source->h)
        if(source->dots[y + 1][x] == n - 1){
            (*dist)->dots[y + 1][x] = 1;
            return mx_get_path(source, dist, x, y + 1, n - 1);
        }
        
    if(y - 1 >= 0)
        if(source->dots[y - 1][x] == n - 1){
            (*dist)->dots[y - 1][x] = 1;
            return mx_get_path(source, dist, x, y - 1, n - 1);
        }
    return false;
}
char *mx_open_file(char *path) {
    int fd = open(path, O_RDWR);
    if(fd < 0)
        mx_printerr_c("map does not exist\n");
    char ch;
    int ref;
    char *result = mx_strnew(0);
    while ((ref = read(fd, &ch, 1)) > 0) {
        if (ref < 0)
            mx_printerr_c("map does not exist\n");
        if(ch != '#' && ch != '.' && ch != ',' && ch != '\n' && ch != '\r')
            mx_printerr_c("map error\n");
        if(ch != '\r')
            result = mx_str_append(result, ch);
    }
    close(fd);
    return result;
}
char *mx_parse_map(Map *map, int startX, int startY, int endX, int endY) {
    mx_wave_func(&map, startX, startY, 0);
    Map *path = NULL;
    if(!mx_get_path(map, &path, endX, endY, 0))
        return NULL;
    int maxDistance = mx_get_max_distance(map);
    char *result = mx_strnew(0);
    for(int i = 0; i < map->h; i++){
        for(int j = 0; j < map->w; j++)
            if(map->dots[i][j] == -2)
                result = mx_str_append(result, '#');
            else if(map->dots[i][j] == -1)
                result = mx_str_append(result, '.');
            else
                if(map->dots[i][j] == maxDistance)
                    if(path->dots[i][j] == 1)
                        result = mx_str_append(result, 'X');
                    else
                        result = mx_str_append(result, 'D');
                else
                    if(path->dots[i][j] == 1)
                        result = mx_str_append(result, '*');
                    else
                        result = mx_str_append(result, '.');
        result = mx_str_append(result, '\n');
    }
    return result;
}
bool mx_isdigit(char c) {
    return c >= '0' && c <= '9';
}

bool mx_isspace(char c) {
    if (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
        return 1;
    }
    else {
        return 0;
    }
}
char **mx_parse_text(char *text) {
    int h = 0;
    for(char *i = text; *i != '\0'; i++)
        if(*i == '\n')
            h++;
    char **tsa = malloc(sizeof(char*)*(h+1));
    char *ts = mx_strnew(0);
    int tsai = 0;
    for(char *i = text; *i != '\0'; i++)
        if(*i == '\n'){
            tsa[tsai++] = ts;
            ts = mx_strnew(0);
        }
        else if(*i == '#' || *i == '.')
            ts = mx_str_append(ts, *i);
    tsa[tsai] = NULL;
    return tsa;
}
void mx_printchar(char c) {
    write(1, &c, 1);
}
void mx_printerr(char *str) {
    write(2, str, mx_strlen(str));
}
void mx_printerr_c(char *str) {
    write(2, str, mx_strlen(str));
    exit(0);
}
void mx_printint(int n) {
    char ar[50];
    int i = 0;
    if (n == 0) write(1, "0", 1);
    if (n == -2147483648) write(1, "2147483648", 11);
    if (n < 0) {
        n *= -1;
        write(1, "-", 1);
    }
    while (n != 0 && n != -2147483648) {
        ar[i++] = n % 10 + '0';
        n /= 10;
    }
    for (int k = i - 1; k >= 0; k--) {
        write(1, &ar[k], 1);
    }
}
void mx_printstr(const char *s) {
    write(1, s, mx_strlen((char *)s));
}
char *mx_str_append(char *str, char symbol){
    int size = mx_strlen(str) + 1;
    char *s = mx_strnew(size);
    for(int i = 0; i < size; i++)
        if(i == size - 1)
            s[i] = symbol;
        else
            s[i] = str[i];
    return s;
}
void mx_wave_func(Map **map, int x, int y, int n) {
    if(
    x < 0 || x >= (*map)->w
    ||
    y < 0 || y >= (*map)->h
    )
        return;
    if((*map)->dots[y][x] == -2)
        return;
    
    if((*map)->dots[y][x] == -1)
        (*map)->dots[y][x] = n;
    
    if(y + 1 < (*map)->h)
        if((*map)->dots[y + 1][x] == -1 || (*map)->dots[y + 1][x] > n + 1)
            (*map)->dots[y + 1][x] = n + 1;
        
    if(y - 1 >= 0)
        if((*map)->dots[y - 1][x] == -1 || (*map)->dots[y - 1][x] > n + 1)
            (*map)->dots[y - 1][x] = n + 1;
        
    if(x + 1 < (*map)->w)
        if((*map)->dots[y][x + 1] == -1 || (*map)->dots[y][x + 1] > n + 1)
            (*map)->dots[y][x + 1] = n + 1;
        
    if(x - 1 >= 0)
        if((*map)->dots[y][x - 1] == -1 || (*map)->dots[y][x - 1] > n + 1)
            (*map)->dots[y][x - 1] = n + 1;
    
    if(y + 1 < (*map)->h)
        if((*map)->dots[y + 1][x] >= n + 1)
            mx_wave_func(map, x, y + 1, n + 1);
        
    if(y - 1 >= 0)
        if((*map)->dots[y - 1][x] >= n + 1)
            mx_wave_func(map, x, y - 1, n + 1);
    
    if(x + 1 < (*map)->w)
        if((*map)->dots[y][x + 1] >= n + 1)
            mx_wave_func(map, x + 1, y, n + 1);
        
    if(x - 1 >= 0)
        if((*map)->dots[y][x - 1] >= n + 1)
            mx_wave_func(map, x - 1, y, n + 1);
}
void mx_write_file(char *path, char *data) {
    int fd = open(path, O_CREAT | O_RDWR);
    write(fd, data, mx_strlen(data));
    close(fd);
}

int mx_strlen(char *s) {
     int size = 0;
     for(char *i = s; *i != '\0'; i++)
         size++;
     return size;
}

char *mx_strnew(const int size) {
    char *memory = NULL;
    int i = 0;

    if (size < 0)
        return NULL;
    memory = (char *)malloc(size + 1);
    while (i < size) {
        memory[i] = '\0';
        i++;
    }
    memory[i] = '\0';
    return memory;
}


