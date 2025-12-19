#include "push_swap.h"

static int calculate_chunk_size(int total_size)
{
    if (total_size <= 100)
        return (total_size / 5);
    else
        return (total_size / 11);
}

static void push_chunk_to_b(t_stack **a, t_stack **b, int start, int end)
{
    int i;
    int size;
    
    size = ft_stack_size(*a);
    i = 0;
    while (i < size && ft_stack_size(*a) > 3)
    {
        if ((*a)->index >= start && (*a)->index <= end)
            pb(a, b);
        else
            ra(a);
        i++;
    }
}

void chunk_sort(t_stack **a, t_stack **b)
{
    int total_size;
    int chunk_size;
    int chunk_start;
    
    total_size = ft_stack_size(*a);
    assign_indexes(*a);
    chunk_size = calculate_chunk_size(total_size);
    
    chunk_start = 0;
    while (ft_stack_size(*a) > 3)
    {
        push_chunk_to_b(a, b, chunk_start, chunk_start + chunk_size - 1);
        chunk_start += chunk_size;
        if (chunk_start >= total_size)
            chunk_start = total_size - 1;
    }
    
    sort_three(a);
    
    while (*b != NULL)
        pa(a, b);
    
    while ((*a)->index != 0)
        ra(a);
}
