#include "list.h"

void mx_push_index(t_list **list, void *data, int index){
    if (*list == NULL || list == NULL) return;
    if (index < 1) {
        mx_push_front(list, data);
        return;
    }
    int c = 0;
    t_list *temp_count = *list;
    while (temp_count) {
        temp_count = temp_count -> next;
        c++;
    }
    if (index >= c) {
        mx_push_back(list, data);
        return;
    }
    t_list *temp = *list;
    t_list *temp2 = NULL;
    for (int i = 0; i < index; i++) {
        temp2 = temp;
        temp = temp -> next;
    }
    temp2 -> next = mx_create_node(data);
    temp2 -> next -> next = temp;
}


