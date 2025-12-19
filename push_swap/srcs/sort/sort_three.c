/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:53:59 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/19 11:07:10 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **a)
{
    int nb1;
    int nb2;
    int nb3;
    
    if (*a == NULL || (*a)->next == NULL || (*a)->next->next == NULL)
        return;
    nb1 = (*a)->value;
    nb2 = (*a)->next->value;
    nb3 = (*a)->next->next->value;
    if (nb1 > nb2 && nb2 < nb3 && nb1 < nb3)
        ra(a);
    else if (nb1 < nb2 && nb2 > nb3 && nb1 < nb3)
        rra(a);
    else if (nb1 > nb2 && nb2 < nb3 && nb1 > nb3)
        sa(a);
    else if (nb1 < nb2 && nb2 > nb3 && nb1 > nb3)
    {
        sa(a);
        rra(a);
    }
    else if (nb1 > nb2 && nb2 > nb3)
    {
        sa(a);
        ra(a);
    }

    // mn b3d
}