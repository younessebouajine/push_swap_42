/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:46:16 by yobouaji          #+#    #+#             */
/*   Updated: 2026/01/03 09:52:12 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <unistd.h>

static void	strip_newline(char *s)
{
	size_t i;

	if (!s)
		return;
	i = 0;
	while (s[i])
		i++;
	if (i > 0 && s[i - 1] == '\n')
		s[i - 1] = '\0';
}

int	main(int argc, char **argv)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	char	*line;

	if (argc < 2)
		return (0);

	if (!parse_args(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		ft_deallocate(&a);
		return (1);
	}


	while ((line = get_next_line(0)) != NULL)
	{
		strip_newline(line);
		if (!execute_op(line, &a, &b))
		{
			free(line);
			write(2, "Error\n", 6);
			ft_deallocate(&a);
			ft_deallocate(&b);
			return (1);
		}
		free(line);
	}

	if (ft_is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	ft_deallocate(&a);
	ft_deallocate(&b);
	return (0);
}
