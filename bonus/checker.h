/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 09:43:27 by yobouaji          #+#    #+#             */
/*   Updated: 2026/01/03 09:45:25 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "push_swap.h"

char	*get_next_line(int fd);
int		execute_op(const char *op, t_stack **a, t_stack **b);

#endif