#include "push_swap.h"

void assign_indexes(t_stack *stack)
{
    t_stack *current;
    t_stack *compare;
    int index;
    
    current = stack;
    while (current != NULL)
    {
        index = 0;
        compare = stack;
        while (compare != NULL)
        {
            if (compare->value < current->value)
                index++;
            compare = compare->next;
        }
        current->index = index;
        current = current->next;
    }
}
