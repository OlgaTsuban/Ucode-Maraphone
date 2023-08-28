#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *, void *)) {
    bool end = false;
    while(!end){
        end = true;
        for(t_list* i = list; i->next != NULL; i = i->next)
            if(cmp(i->data, i->next->data)){
                end = false;
                void *t = i->data;
                i->data = i->next->data;
                i->next->data = t;
            }
    }
    return list;
}


