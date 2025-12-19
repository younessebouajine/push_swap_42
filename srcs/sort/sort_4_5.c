#include "push_swap.h"

static void push_min_to_b(t_stack **a, t_stack **b, int size)
{
    int min_pos;
    int i;
    
    min_pos = find_min_position(*a);
    
    if (min_pos <= size / 2)
    {
        i = 0;
        while (i++ < min_pos)
            ra(a);
    }
    else
    {
        i = 0;
        while (i++ < size - min_pos)
            rra(a);
    }
    pb(a, b);
}

void sort_4_5(t_stack **a, t_stack **b, int size)
{
    push_min_to_b(a, b, size);
    if (size == 5)
        push_min_to_b(a, b, size - 1);
    
    sort_three(a);
    
    pa(a, b);
    if (size == 5)
        pa(a, b);
}
