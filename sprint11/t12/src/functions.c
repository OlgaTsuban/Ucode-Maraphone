#include "../inc/list.h"

long mx_atoi(const char* str) {
    if (*str == '0') return 0;
    long n = 0;
    long c = 0;
    if (str[0] == '-') {
        c = 1;
        str++;
    }
    while(*str >= '0' && *str <= '9') {
        n *= 10;
        if (!mx_isdigit(*str) || mx_isspace(*str)) return -1;
        n += *str++;
        if (*str && (!mx_isdigit(*str) || mx_isspace(*str))) return -1;
        n -= '0';
    }
    if (*str != '\0') return -1;
    if(c == 1)
        n *= -1;
    return n;
}

void mx_clear_list(t_list **list) {
    if (!*list) return;
    t_list *temp;
    while (*list) {
        temp = (*list) -> next;
        (*list) -> next = NULL;
        free(*list);
        *list = temp;
    }
}

t_list *mx_create_node(void *data) {
    t_list *newNode = (t_list*)malloc(16);
    newNode -> next = NULL;
    newNode -> data = data;
    return newNode;
}

bool mx_isdigit(char c) {
    return (char)c >= '0' && (char)c <= '9';
}

bool mx_isspace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
}

int mx_list_size(t_list *list) {
    if (list == NULL) {
        return 0;
    }
    int counter = 0;

    while(list) {
        list = list->next;
        counter++;
    }
    
    return counter;
}

void mx_pop_back(t_list **list) {
    if (*list == NULL || list == NULL) {
        return;
    }

    if ((*list)->next == NULL) {
        free(*list);
        *list = NULL;
        return;
    }
    t_list *current = *list;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    current = NULL;
}

void mx_pop_front(t_list **list) {
   if (*list == NULL ) {
        return;
    }
    t_list *current = *list;
    *list = current -> next;
    free(current);
    current = NULL;
}

void mx_pop_index(t_list **list, int index) {
    if (!*list) return;
    t_list *temp = *list, *helper = NULL;
    if (index < 1 || temp -> next == NULL) {
        *list = temp -> next;
        free(temp);
        temp = NULL;
        return;
    }
    for (int i = 0; i < index; i++) {
        if (temp -> next == NULL)
            break;
        helper = temp;
        temp = temp -> next;
    }
    helper -> next = temp -> next;
    free(temp);
    temp = NULL;
    return;
}
void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}

void mx_printint(int n) {
    if(n == 0) {
        mx_printchar(48);
        return;
    }
    if( n < 0) {
        mx_printchar(45);
        n *= -1;
    }
    int start = n;
    int i = 0;
    while(start != 0) {
        start = start / 10;
        i++;
    }
    int array[i];
    int counter_arr = 0;
    while(n != 0) {
        array[counter_arr] = n % 10;
        n = n / 10;
        counter_arr++;
    }
    for(int j = counter_arr - 1; j >= 0; j--) {
        mx_printchar(array[j] + 48);
    }
}

void mx_printstr(const char* s) {
    write(1,  s, mx_strlen(s));
}

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL || list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp = *list;
    while (temp -> next) {
        temp = temp -> next;
    }
    temp -> next = mx_create_node(data);
}

void mx_push_front(t_list **list, void *data) {
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    t_list *temp = mx_create_node(data);
    temp -> next = *list;
    *list = temp;
}

void mx_push_index(t_list **list, void *data, int index) {
    if (!*list) {
        *list = mx_create_node(data);
        return;
    }
    if (index < 1) {
        mx_push_front(list, data);
        return;
    }
    int count = 0;
    t_list *temp_count = *list;
    while (temp_count) {
        temp_count = temp_count -> next;
        count++;
    }
    if (index >= count) {
        mx_push_back(list, data);
        return;
    }
    t_list *temp = *list, *helper = NULL;
    for (int i = 0; i < index; i++) {
        helper = temp;
        temp = temp -> next;
    }
    helper -> next = mx_create_node(data);
    helper -> next -> next = temp;
}


int mx_strcmp_changed (const char *s1, const char *s2) {
    for( ; mx_tolower(*s1) == mx_tolower(*s2); ++s1, ++s2 )
        if ( mx_tolower(*s2) == '\0' )
            return 0;
    return mx_tolower(*s1) - mx_tolower(*s2);
}

bool cmp(void *a, void *b) {
    if (mx_strcmp_changed((char*)(a), (char*)(b)) > 0) return true;
    return false;
}

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (cmp == NULL || list == NULL) return list;
    t_list *temp = list;
    int count = 0;
    while (temp) {
        temp = temp -> next;
        count++;
    }

    for (int i = 0; i < count; i++) {
        temp = list;
        for (int j = 0; j < count - 1; j++) {
            if (cmp(temp -> data, temp -> next -> data)) {
                void *data = temp -> data;
                temp -> data = temp -> next -> data;
                temp -> next -> data = data;
            }
            temp = temp -> next;
        }
    }
    return list;
}

int mx_strcmp (const char *s1, const char *s2) {
    for( ; *s1 == *s2; ++s1, ++s2 )
        if ( *s2 == '\0' )
            return 0;
    return *s1 - *s2;
}

char *mx_strcpy(char* dst, const char* src) {
    int count = 0;
    while(*src) {
        *dst++ = *src++;
        count++;
    }
    dst -= count;
    return dst;
}


int mx_strlen(const char *s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

int mx_strncmp(const char *s1, const char *s2, int n) {
    int i = 0;
    while (*s1 == *s2 && (*s1 != '\0' || i != n-1)) {
        s1++;
        s2++;
        i++;
        if (*s1 == '\0' || i == n-1) {
            return *s1 - *s2;
        }
        
    }
    return *s1 - *s2;
}

int mx_tolower(int c) {
    if (c >= 97)
        return c;
    else
        return c + 32;
}

