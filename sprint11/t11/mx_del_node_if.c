#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    t_list *buff;
    t_list *pbuff = *list;
    if ((buff = (*list)->next))
    {
        while (buff->next)
        {
            if (cmp(buff->data, del_data))
            {
                pbuff->next = buff->next;
                free(buff);
                buff = pbuff->next;
            }
            else
            {
                pbuff = pbuff->next;
                buff = buff->next;
            }
        }
        if (cmp(buff->data, del_data))
        {
            pbuff->next = NULL;
            free(buff);
        }
        
        buff = *list;
        if (cmp(buff->data, del_data))
        {
            (*list) = (*list)->next ;
            free(buff);
        }
    }
    else {
        if (cmp(pbuff->data, del_data))
            free(*list);
    }
}


