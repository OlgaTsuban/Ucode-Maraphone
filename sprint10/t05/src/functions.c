#include "../inc/header.h"

int mx_atoi(const char *str) {
    int result = 0;
    bool sign = false;
    if(*str) {
        while(mx_isspace(*str))
            str++;
        if (*str == '-') {
            sign = true;
            str++;
        }
        else if (*str == '+')
            str++;
        while (mx_isdigit(*str)) {
            result *= 10;
            if (sign)
                result -= *str-48;
            else
                result += *str-48;
            str++;
        }
    }
    return result;
}

t_agent *mx_create_agent(char *name, int power, int strength) {
    t_agent *instance = NULL;

    if (name == NULL)
        return NULL;
    instance = (t_agent *)malloc(sizeof(t_agent));
    instance->name = mx_strdup(name);
    instance->power = power;
    instance->strength = strength;
    return instance;
}

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    t_agent **agent_array = NULL;
    
    agent_array = (t_agent **)malloc(sizeof(t_agent *) * count + 1);
    if (name == NULL || power == NULL || strength == NULL)
        return NULL;
    for (int i = 0; i < count; i++)
        agent_array[i] = mx_create_agent(name[i], power[i], strength[i]);
    agent_array[count] = NULL;

    return agent_array;
}

void mx_exterminate_agents(t_agent ***agents) {
     t_agent **buff = *agents;

    for (int i = 0; buff[i]; i++) {
        mx_printchar('!');
        mx_printchar('\n');
        free(buff[i]->name);
        free(buff[i]);
    }
    mx_printchar('\n');
    free(*agents);
    *agents = NULL;
}

char *mx_file_to_str(const char *filename) {
    if (filename) {
        int src = open(filename, O_RDONLY);

        if (src > 0) {
            char buff[64], *text = NULL;
            int rd = read(src, &buff, sizeof(buff));
            int count = rd;
            
            if (rd) {
                while (rd == 64) {
                    rd = read(src, &buff, sizeof(buff));
                    count += rd;
                }
                close(src);
                text = (char *)malloc(sizeof(char) * count + 1);
                src = open(filename, O_RDONLY);
                rd = read(src, text, count);
                text[count] = '\0';
                close(src);
                return text;
            }
        }
        close(src);
    }
    return NULL;
}

bool mx_isdigit(int c) {
    if (c > 47 && c < 59)
        return true;
    return false;
}

bool mx_isspace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == 'r')
        return true;
    return false;
}

void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

void mx_printint(int n) {
    if (n < 0)
        mx_printchar('-');
    if (n / 10)
        mx_printint((unsigned)n/10);
    mx_printchar((unsigned)n%10 + 48);
}

void mx_printstr(const char *s) {
    write(1, s, mx_strlen(s));
}
char *mx_strcat(char *s1, const char *s2) {
    int l = mx_strlen(s1);
    for(int i = 0; i < mx_strlen(s2); i++)
        s1[l++] = s2[i];
    s1[l] = '\0';
    return s1;
}

char *mx_strchr(const char *str, int c) {
    while(*str) {
        if(*str == c)
            return (char *)str;
    str++;
    }
    return 0;
}

int mx_strcmp(const  char *s1, const char *s2) {
    int count = 0;

    while (s1[count] == s2[count]) {
        if (s1[count] == '\0')
            return 0;
        count++;
    }
    return s1[count]-s2[count];
}

char *mx_strcpy(char *dst, const char *src){
    char *save = dst;
    for (; (*dst = *src) != '\0'; ++src, ++dst);
    return(save);
}


char *mx_strdup(const char *str){
    int size = mx_strlen(str);
    char *r = mx_strnew(size);
    mx_strcpy(r, str);
    return r;
}


char *mx_strjoin(char const *s1, char const *s2){
    if(s1 == NULL || s2 == NULL)
        return (s1 == NULL && s2 == NULL)?NULL:((s1 == NULL)?mx_strdup(s2):mx_strdup(s1));
    return mx_strcat(mx_strdup(s1), s2);
}



int mx_strlen(const char *s) {
    int count = 0;
    while(s[count] != '\0') {
        count++;
    }
    return count;
}

int mx_strncmp(const char *s1, const char *s2, int n) {
    int count = 0;

    while (s1[count] == s2[count]) {
        if (s1[count] == '\0' || count+1 == n)
            return 0;
        count++;
    }
    return s1[count]-s2[count];
}

char *mx_strncpy(char *dst, const char *src, int len) {
    char *start = dst;

    while (len) {
        if(*src)
            *dst = *src;
        else
            *dst = '\0';
        src++;
        dst++;
        len--;
    }
    return start;
}

char *mx_strnew(const int size){
    if(size < 0)
        return NULL;
    char *r = (char *)malloc(sizeof(char)*size+1);
    for(int i = 0; i < size+1; i++)
        r[i] = '\0';
    return r;
}

char *mx_strstr(const char *s1, const char *s2) {
    int offset = 0;
    
    while (offset + mx_strlen(s2) <= mx_strlen(s1)) {
        if (!mx_strncmp(s1+offset, s2, mx_strlen(s2)))
            return (char *)s1 + offset;
        offset++;
    }
    return 0;
}



