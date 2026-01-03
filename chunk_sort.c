/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:06:57 by yobouaji          #+#    #+#             */
/*   Updated: 2026/01/02 11:00:26 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	calculate_chunk_size(int total_size)
{
	if (total_size <= 100)
		return (total_size / 5 + 1);
	else
		return (total_size / 11 + 1);
}

static void push_chunk_to_b(t_stack **a, t_stack **b, int start, int end)
{
	int	size;
	int	rotations;
	int	pushed;
	int	chunk_len;

	size = ft_stack_size(*a);
	chunk_len = end - start + 1;
	rotations = 0;
	pushed = 0;

	while (pushed < chunk_len && rotations < size)
	{
		if ((*a)->index >= start && (*a)->index <= end)
		{
			pb(a, b);
			pushed++;
			rotations = 0;
			size--;
		}
		else
		{
			ra(a);
			rotations++;
		}
	}
}


static int	find_max_index_position(t_stack *stack)
{
	int		max_index;
	int		position;
	int		current_pos;
	t_stack	*current;

	if (!stack)
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

static void	push_max_to_a(t_stack **a, t_stack **b)
{
	int	max_pos;
	int	size;

	size = ft_stack_size(*b);
	max_pos = find_max_index_position(*b);
	
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(b);
	}
	else
	{
		max_pos = size - max_pos;
		while (max_pos-- > 0)
			rrb(b);
	}
	pa(a, b);
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int	total_size;
	int	chunk_size;
	int	chunk_start;
	int	num_chunks;

	total_size = ft_stack_size(*a);
	assign_indexes(*a);
	chunk_size = calculate_chunk_size(total_size);
	num_chunks = (total_size + chunk_size - 1) / chunk_size;

	chunk_start = 0;
	while (chunk_start < total_size && ft_stack_size(*a) > 3)
	{
		int chunk_end = chunk_start + chunk_size - 1;

		if (chunk_end >= total_size)
			chunk_end = total_size - 1;

		push_chunk_to_b(a, b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}

	if (ft_stack_size(*a) == 3)
		sort_three(a);
	else if (ft_stack_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}

	while (*b)
		push_max_to_a(a, b);
}
