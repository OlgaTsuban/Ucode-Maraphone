#ifndef CREATE_NEW_AGENTS_H
#define CREATE_NEW_AGENTS_H

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

char *mx_strnew(const int size);

char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);

char *mx_strdup(const char *str);

t_agent *mx_create_agent(char*, int, int);
t_agent **mx_create_new_agents(char**, int*, int*, int);

#endif
