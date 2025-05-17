#include "../include/so_long.h"

t_comp  *new_component(char type)
{
    t_comp  *new;

    new = malloc(sizeof(t_comp));
    if (!new)
        return (NULL);
    new->type = type;
    new->count = 0;
    new->next = NULL;
    return (new);
}

void add_component(t_comp **list, char type)
{
    t_comp *tmp = *list;

    while (tmp)
    {
        if (tmp->type == type)
        {
            tmp->count++;
            return;
        }
        tmp = tmp->next;
    }
    t_comp *new = new_component(type);
    if (!new)
        return;
    new->next = *list;
    *list = new;
}
