/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:58:53 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/19 11:21:01 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

static long	ft_atol(const char *s)
{
	long	value;
	long	mark;

	value = 0;
	mark = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		mark = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
	{
		value = value * 10 + (*s - '0');
		s++;
	}
	return (value * mark);
}

int	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	long	value;
	t_stack	*new_node;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		new_node = create_node((int)value);
		if (!new_node)
			return (0);
		ft_add_end(stack_a, new_node);
		i++;
	}
	if (has_duplicates(*stack_a))
		return (0);
	return (1);
}