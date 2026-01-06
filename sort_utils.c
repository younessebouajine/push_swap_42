/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:05:16 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/20 17:03:44 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

int	find_min_position(t_stack *stack)
{
	int		min;
	int		position;
	int		current_pos;

	if (!stack)
		return (0);
	min = stack->value;
	position = 0;
	current_pos = 0;
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			position = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (position);
}
