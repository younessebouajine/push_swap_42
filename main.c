#include "push_swap.h"
#include <unistd.h>

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        return (0);

    if (parse_args(ac, av, &stack_a) == 0)
    {
        write(2, "Error\n", 6);
        ft_deallocate(&stack_a);
        return (1);
    }


    if (stack_a == NULL)
        return (0);

    if (ft_is_sorted(stack_a))
    {
        ft_deallocate(&stack_a);
        return (0);
    }


    if (ft_stack_size(stack_a) == 2)
    {
        if (stack_a->value > stack_a->next->value)
            sa(&stack_a);
    }
    else if (ft_stack_size(stack_a) == 3)
        sort_three(&stack_a);
    else if (ft_stack_size(stack_a) == 4 || ft_stack_size(stack_a) == 5)
        sort_4_5(&stack_a, &stack_b, ft_stack_size(stack_a));
    else if (ft_stack_size(stack_a) > 5)
        chunk_sort(&stack_a, &stack_b);


    ft_deallocate(&stack_a);
    return (0);
}