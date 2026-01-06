/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:48:54 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/22 12:38:11 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->index = -1;
    new_node->next = NULL;
    return (new_node);
}

void ft_add_end(t_stack **stack, t_stack *new_node)
{
    t_stack *last;

    if (!stack || !new_node)
        return;
    if (*stack == NULL)
    {
        *stack = new_node;
        return;
    }
    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void ft_deallocate(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack)
        return;
    
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

int ft_stack_size(t_stack *stack)
{
    int counter = 0;
    
    while (stack != NULL)
    {
        counter++;
        stack = stack->next;
    }
    return (counter);
}

int ft_is_sorted(t_stack *stack)
{
    while (stack != NULL && stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

t_stack *find_last_node(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}
