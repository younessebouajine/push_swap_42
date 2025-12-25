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
	int min;
	int position;
	int i;
	
	if (stack == NULL)
		return (0);
	
	min = stack->value;
	position = 0;
	i = 0;
	
	while (stack != NULL)
	{
		if (stack->value < min)
		{
			min = stack->value;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}
