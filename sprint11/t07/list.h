#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list{
    void *data;
    struct s_list *next;
}              t_list;

void mx_pop_back(t_list**);
void mx_pop_front(t_list **);
void mx_pop_index(t_list **, int);

#endif

