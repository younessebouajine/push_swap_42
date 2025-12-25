#include "push_swap.h"

void sort_three(t_stack **a)
{
    int first;
    int second;
    int third;
    
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
    
    first = (*a)->value;
    second = (*a)->next->value;
    third = (*a)->next->next->value;
    

    if (first < second && second > third && first < third)
    {
        rra(a);
        sa(a);
    }

    else if (first > second && second < third && first < third)
        sa(a);

    else if (first < second && second > third && first > third)
        rra(a);

    else if (first > second && second < third && first > third)
        ra(a);

    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
}
