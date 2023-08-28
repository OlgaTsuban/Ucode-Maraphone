#include "only_smiths.h"
t_agent *mx_create_agent(char *name, int power, int strength) {
  if (!name) return NULL;
  
  t_agent *r = NULL;
  r = (t_agent *) malloc(sizeof(t_agent));
  if (!r) return NULL;

  r->name = mx_strdup(name);
  if (r->name == NULL) return NULL;

  r->power = power;
  r->strength = strength;
  return r;
}



