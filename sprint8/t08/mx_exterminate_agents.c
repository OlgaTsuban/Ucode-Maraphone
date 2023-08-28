#include "exterminate_agents.h"

void mx_exterminate_agents(t_agent ***agents) {
    t_agent **p = *agents;
    int i = 0;
    while (p[i] != NULL) {
        free(p[i]->name);
        free(p[i]);

        i++;
    }
    free(*agents);
    *agents = NULL;
}



