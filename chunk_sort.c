/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:06:57 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/22 12:46:42 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
    int size;
    int rotations;
    
    size = ft_stack_size(*a);
    rotations = 0;
    
    while (ft_stack_size(*a) > 3 && rotations < size)
    {
        if ((*a)->index >= start && (*a)->index <= end)
        {
            pb(a, b);
            rotations = 0;  // Reset rotation counter when we push
            size = ft_stack_size(*a);  // Update size
        }
        else
        {
            ra(a);
            rotations++;  // Count rotations to prevent infinite loop
        }
    }
}

static int find_max_index_position(t_stack *stack)
{
    int max_index;
    int position;
    int current_pos;
    t_stack *current;
    
    if (! stack)
        return (0);
    
    max_index = stack->index;
    position = 0;
    current_pos = 0;
    current = stack;
    
    while (current)
    {
        if (current->index > max_index)
        {
            max_index = current->index;
            position = current_pos;
        }
        current = current->next;
        current_pos++;
    }
    return (position);
}

static void push_max_to_a(t_stack **a, t_stack **b)
{
    int max_pos;
    int size;
    
    size = ft_stack_size(*b);
    max_pos = find_max_index_position(*b);
    
    if (max_pos <= size / 2)
    {
        while (max_pos-- > 0)
            rb(b);
    }
    else
    {
        while (max_pos++ < size)
            rrb(b);
    }
    pa(a, b);
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
    }
    
    sort_three(a);
    
    while (*b != NULL)
        push_max_to_a(a, b);
}
