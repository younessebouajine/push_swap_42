#include "push_swap.h"
#include <unistd.h>

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;

    if (parse_args(ac, av, &stack_a) == 0)
    {
        write (2, "Error\n", 6);
        ft_deallocate(&stack_a);
        return (1);
    }

    // DEBUG: Print what we parsed
    // write(1, "DEBUG: Parsed ", 14);
    t_stack *tmp = stack_a;
    while (tmp)
    {
        // Can't easily print int, but we can check with gdb
        tmp = tmp->next;
    }
    // write(1, "\n", 1);

    if (ft_is_sorted(stack_a))
    {
        // write(1, "DEBUG: Already sorted\n", 22);
        ft_deallocate(&stack_a);
        return (0);
    }

    if (ft_stack_size(stack_a) == 2)
    {
        // write(1, "DEBUG: 2 elements, checking...\n", 31);
        if (stack_a->value > stack_a->next->value)
        {
            // write(1, "DEBUG: Calling sa()\n", 20);
            sa(&stack_a);
        }
    }
    if (ft_stack_size(stack_a) == 3)
    {
        // write(1, "DEBUG: 3 elements, calling sort_three()\n", 40);
        sort_three(&stack_a);
    }

    // In main.c, after checking for 3 numbers:
    if (ft_stack_size(stack_a) == 4 || ft_stack_size(stack_a) == 5)
        sort_4_5(&stack_a, &stack_b, ft_stack_size(stack_a));
    ft_deallocate(&stack_a);
    // write(1, "DEBUG: Program ended\n", 21);
    return (0);
}
