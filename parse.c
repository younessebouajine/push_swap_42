/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:05:59 by yobouaji          #+#    #+#             */
/*   Updated: 2026/01/03 10:08:43 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <limits.h>

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
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (! ft_isdigit(str[i]))
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

static long	ft_atoi(const char *s)
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

static int	process_number(char *str, t_stack **stack_a)
{
	long	value;
	t_stack	*new_node;

	if (!is_valid_number(str))
		return (0);
	value = ft_atoi(str);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	new_node = create_node((int)value);
	if (!new_node)
		return (0);
	ft_add_end(stack_a, new_node);
	return (1);
}

static int	process_split_arg(char *arg, t_stack **stack_a)
{
	char	**split;
	int		j;

	if (! arg || *arg == '\0')
		return (1);
	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	if (split[0] == NULL)
	{
		free_split(split);
		return (1);
	}
	j = 0;
	while (split[j])
	{
		if (!process_number(split[j], stack_a))
		{
			free_split(split);
			return (0);
		}
		j++;
	}
	free_split(split);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (! process_split_arg(argv[i], stack_a))
				return (0);
		}
		else
		{
			if (!process_number(argv[i], stack_a))
				return (0);
		}
		i++;
	}
	if (has_duplicates(*stack_a))
		return (0);
	return (1);
}


// " -------999 "