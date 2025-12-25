/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobouaji <yobouaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:07:26 by yobouaji          #+#    #+#             */
/*   Updated: 2025/12/22 12:35:50 by yobouaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
}   t_stack;

// Stack utilities
t_stack *create_node(int value);
void    ft_add_end(t_stack **stack, t_stack *new_node);
void    ft_deallocate(t_stack **stack);
int     ft_stack_size(t_stack *stack);
int     ft_is_sorted(t_stack *stack);

// Operations
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

// Sorting
void    sort_three(t_stack **a);
void    sort_4_5(t_stack **a, t_stack **b, int size);
void    chunk_sort(t_stack **a, t_stack **b);
int     find_min_position(t_stack *stack);

// Parsing & Validation
int     parse_args(int argc, char **argv, t_stack **a);
int     is_valid_number(char *str);
int     has_duplicates(t_stack *stack);

// Indexing
void    assign_indexes(t_stack *stack);

// String utilities
int     ft_strchr(char *s, char c);
char    **ft_split(char const *s, char c);
void    free_split(char **split);

#endif
