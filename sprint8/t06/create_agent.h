#ifndef CREATE_AGENT_H
#define CREATE_AGENT_H

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

t_agent *mx_create_agent(char *name, int power, int strength);

char *mx_strnew(const int size);

int mx_strlen(const char *s);

char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str);

#endif


