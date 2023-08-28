#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if (!*list) return;
    
    int size = 0;
    t_list *t = *list;
    
    while(t != NULL) {
        t = t->next;
        size++;
    }
    
    if(index >= size - 1) {
        mx_pop_back(list);
    }
    else if(index <= 0) {
        mx_pop_front(list);
    }
    else {
        t = *list;
        int t = 0;
        while(t < index-1) {
            t = t->next;
            t++;
        }
        t_list *temp1 = t->next;
        t->next = t->next->next;
        free(temp1);
    }
}



