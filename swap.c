/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 07:58:17 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/20 15:26:46 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if (*a == NULL || (*a)->next == NULL)
        return;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    write (1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (*b == NULL || (*b)->next == NULL)
        return;
    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    write (1, "sb\n", 3);

   // ft_printf("sb\n");
}

void    ss(t_stack **a, t_stack **b)
{
    if (*a && (*a)->next)
    {
        t_stack *first = *a;
        t_stack *second = first->next;
        first->next = second->next;
        second->next = first;
        *a = second;
    }
    if (*b && (*b)->next)
    {
        t_stack *first = *b;
        t_stack *second = first->next;
        first->next = second->next;
        second->next = first;
        *b = second;
    }
    write (1, "ss\n", 3);

    // ft_printf("ss\n");
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *top_b;

    if(*b == NULL)
        return;
    top_b = *b;
    *b = top_b->next;
    top_b->next = *a;
    *a = top_b;
    write (1, "pa\n", 3);

    // ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *top_a;

    if (*a == NULL)
        return;
    top_a = *a;
    *a = top_a->next;
    top_a->next = *b;
    *b = top_a;
    write (1, "pb\n", 3);

    // ft_printf("pb\n");
}

static void rotate(t_stack **s)
{
    t_stack *first;
    t_stack *last;

    if (!*s || !(*s)->next)
        return;

    first = *s;
    *s = first->next;

    last = *s;
    while (last->next)
        last = last->next;

    last->next = first;
    first->next = NULL;
}

void ra(t_stack **a)
{
    rotate(a);
    write (1, "ra\n", 3);
    
    // ft_printf("ra\n");
}

void rb(t_stack **b)
{
    rotate(b);
    write (1, "rb\n", 3);

    // ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write (1, "rr\n", 3);

    // ft_printf("rr\n");
}

static void reverse_rotate(t_stack **s)
{
    t_stack *prev;
    t_stack *last;

    if (!*s || !(*s)->next)
        return;

    prev = *s;
    while (prev->next->next)
        prev = prev->next;

    last = prev->next;
    prev->next = NULL;
    last->next = *s;
    *s = last;
}

void rra(t_stack **a)
{
    reverse_rotate(a);
    write (1, "rra\n", 4);

    // ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    reverse_rotate(b);
    write (1, "rrb\n", 4);

    // ft_printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write (1, "rrr\n", 4);

    // ft_printf("rrr\n");
}
