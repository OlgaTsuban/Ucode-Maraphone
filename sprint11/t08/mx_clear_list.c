#include "list.h"

void mx_clear_list(t_list **list) {
    if(*list == NULL) return;
    while ((*list)->next != NULL) {
        
        t_list *now = *list;
        while(now->next->next != NULL) {
            now = now->next;
        }
        free(now->next);
        now->next = NULL;
    }
    free(*list);
    *list = NULL;
}


