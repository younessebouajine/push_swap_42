/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:45:53 by yobouaji          #+#    #+#             */
/*   Updated: 2026/01/03 09:45:55 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

/* Local string equality (no libc functions used) */
static int	str_eq(const char *s, const char *t)
{
	if (!s || !t)
		return (0);
	while (*s && *t)
	{
		if (*s != *t)
			return (0);
		s++;
		t++;
	}
	return (*s == '\0' && *t == '\0');
}

/* Non-printing stack operations (mirror of swap.c) */

static void	op_sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;

	if (!a || !*a || !(*a)->next)
		return;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static void	op_sb(t_stack **b)
{
	t_stack *first;
	t_stack *second;

	if (!b || !*b || !(*b)->next)
		return;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

static void	op_ss(t_stack **a, t_stack **b)
{
	op_sa(a);
	op_sb(b);
}

static void	op_pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!b || !*b)
		return;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

static void	op_pb(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	if (!a || !*a)
		return;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
}

static void	op_ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	if (!a || !*a || !(*a)->next)
		return;
	first = *a;
	*a = first->next;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

static void	op_rb(t_stack **b)
{
	t_stack *first;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return;
	first = *b;
	*b = first->next;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

static void	op_rr(t_stack **a, t_stack **b)
{
	op_ra(a);
	op_rb(b);
}

static void	op_rra(t_stack **a)
{
	t_stack *prev;
	t_stack *last;

	if (!a || !*a || !(*a)->next)
		return;
	prev = *a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

static void	op_rrb(t_stack **b)
{
	t_stack *prev;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return;
	prev = *b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

static void	op_rrr(t_stack **a, t_stack **b)
{
	op_rra(a);
	op_rrb(b);
}

/* Public entry used by the checker main loop */
int	execute_op(const char *op, t_stack **a, t_stack **b)
{
	if (str_eq(op, "sa"))
		op_sa(a);
	else if (str_eq(op, "sb"))
		op_sb(b);
	else if (str_eq(op, "ss"))
		op_ss(a, b);
	else if (str_eq(op, "pa"))
		op_pa(a, b);
	else if (str_eq(op, "pb"))
		op_pb(a, b);
	else if (str_eq(op, "ra"))
		op_ra(a);
	else if (str_eq(op, "rb"))
		op_rb(b);
	else if (str_eq(op, "rr"))
		op_rr(a, b);
	else if (str_eq(op, "rra"))
		op_rra(a);
	else if (str_eq(op, "rrb"))
		op_rrb(b);
	else if (str_eq(op, "rrr"))
		op_rrr(a, b);
	else
		return (0);
	return (1);
}