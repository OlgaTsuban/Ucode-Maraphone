#include "../inc/header.h"

int mx_count_agents(char *src) {
    int count = 0;
    if (src) {
        while (mx_strstr(src, "agent {")) {
            src = mx_strstr(src, "agent {");
            src += 7;
            while (mx_isspace(src[0]))
                src++;
            if(!mx_strncmp(src, "name:", 5)) {
                src = mx_strchr(src, '\n');
                while (mx_isspace(src[0]))
                    src++;
                if(!mx_strncmp(src, "power:", 6)) {
                    src = mx_strchr(src, '\n');
                    while (mx_isspace(src[0]))
                        src++;
                    if(!mx_strncmp(src, "strength:", 9)) {
                        src = mx_strchr(src, '\n');
                        while (mx_isspace(src[0]))
                            src++;
                        if (src[0] == '}')
                            count++;
                        else return -1;
                    }
                    else return -1;
                }
                else return -1;
            }
            else
                return -1;
        }
        src++;
        while (mx_isspace(src[0]))
            src++;
        if (src[0] != '\0') return -1;
        return count;
    }
    return -1;
}
t_agent **mx_parse_agents(char *src, int count) {
    t_agent **dst = (t_agent **)malloc(sizeof(t_agent *) * count + 1);
    int strength, power, n_count, i = 0;
    char *name = NULL;
    dst[count] = NULL;
    if (src) {
        while (i < count) {
            src = mx_strstr(src, "name: ");
            src += 6;
            n_count = 0;
            while (src[n_count] != '\n')
                n_count++;
            name = mx_strnew(n_count);
            name = mx_strncpy(name, src, n_count);

            src = mx_strstr(src, "power: ");
            src += 7;
            power = mx_atoi(src);
            
            src = mx_strstr(src, "strength: ");
            src += 10;
            strength = mx_atoi(src);
            dst[i] = mx_create_agent(name, power, strength);
            i++;
        }
        return dst;
    }
    return NULL;
}
void sort_agents(t_agent ***agent_set, char *flag) {
    int p_b, s_b, size = 1;
    char *n_b;
    while ((*agent_set)[size])
        size++;
    if(!mx_strcmp(flag, "-p")) {
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size - i; j++)
                if((*agent_set)[j]->power > (*agent_set)[j + 1]->power) {
                    p_b = (*agent_set)[j]->power;
                    s_b = (*agent_set)[j]->strength;
                    n_b = (*agent_set)[j]->name;
                    (*agent_set)[j]->power = (*agent_set)[j + 1]->power;
                    (*agent_set)[j]->strength = (*agent_set)[j + 1]->strength;
                    (*agent_set)[j]->name = (*agent_set)[j + 1]->name;
                    (*agent_set)[j+1]->power = p_b;
                    (*agent_set)[j+1]->strength = s_b;
                    (*agent_set)[j+1]->name = n_b;
                }
    }
    else if (!mx_strcmp(flag, "-s")) {
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size - i; j++)
                if((*agent_set)[j]->strength > (*agent_set)[j + 1]->strength) {
                    p_b = (*agent_set)[j]->power;
                    s_b = (*agent_set)[j]->strength;
                    n_b = (*agent_set)[j]->name;
                    (*agent_set)[j]->power = (*agent_set)[j + 1]->power;
                    (*agent_set)[j]->strength = (*agent_set)[j + 1]->strength;
                    (*agent_set)[j]->name = (*agent_set)[j + 1]->name;
                    (*agent_set)[j+1]->power = p_b;
                    (*agent_set)[j+1]->strength = s_b;
                    (*agent_set)[j+1]->name = n_b;
                }
    }
    else if (!mx_strcmp(flag, "-n")) {
        for (int i = 1; i < size; i++)
            for (int j = 0; j < size - i; j++)
                if(mx_strcmp((*agent_set)[i]->name, (*agent_set)[j + 1]->name) > 0) {
                    p_b = (*agent_set)[j]->power;
                    s_b = (*agent_set)[j]->strength;
                    n_b = (*agent_set)[j]->name;
                    (*agent_set)[j]->power = (*agent_set)[j + 1]->power;
                    (*agent_set)[j]->strength = (*agent_set)[j + 1]->strength;
                    (*agent_set)[j]->name = (*agent_set)[j + 1]->name;
                    (*agent_set)[j+1]->power = p_b;
                    (*agent_set)[j+1]->strength = s_b;
                    (*agent_set)[j+1]->name = n_b;
                }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3
        ||
        (
         mx_strcmp(argv[1], "-n") != 0
         &&
         mx_strcmp(argv[1], "-s") != 0
         &&
         mx_strcmp(argv[1], "-p")) != 0
        )
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
    else {
        char *src = mx_file_to_str(argv[2]);
        if (!src)
            mx_printerr("error\n");
        else {
            int count = mx_count_agents(src);
            if(count == -1)
                mx_printerr("error\n");
            else {
                t_agent **agent_set = mx_parse_agents(src, count);
                sort_agents(&agent_set, argv[1]);
                for (int i = 0; agent_set[i] != NULL; i++) {
                    mx_printstr("agent: ");
                    mx_printstr(agent_set[i]->name);
                    mx_printstr(", strength: ");
                    mx_printint(agent_set[i]->strength);
                    mx_printstr(", power: ");
                    mx_printint(agent_set[i]->power);
                    mx_printchar('\n');
                }
            }
        }
    }
    return 0;
}


