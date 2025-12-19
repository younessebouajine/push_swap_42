#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
    int content;
    struct s_list *next;
} t_list; 


void ft_insert_end(t_list **root, int value){
	t_list *new_node = malloc (sizeof(t_list));
	if (!new_node) exit(1);

	new_node->next = NULL;
	new_node->content = value;

	if (*root == NULL){
		*root = new_node;
		return;
	}
	t_list *ptr = *root;
	while (ptr->next){
		ptr = ptr->next;
	}
	ptr->next = new_node;
}

void ft_deallocate(t_list **root){
	t_list *ptr = *root;
	while (ptr != NULL){
		t_list *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	*root = NULL;
}

void ft_insert_first(t_list **root, int value){
	t_list *new_node = malloc(sizeof(t_list));
	if(!new_node) exit(1);

	new_node->content = value;
	new_node->next = *root;
	*root = new_node;
}

void	ft_add_after(t_list *node, int value){
	t_list *new_node = malloc (sizeof(t_list));
	if (!new_node) exit(1);

	new_node->content = value;

	new_node->next = node->next;
	node->next = new_node;
}


int main(){
	t_list *root = NULL;
	// root = malloc(sizeof(t_list));
	// if (!root) exit (2);
	// root->content = 3;
	// root->next = NULL;

	// ft_insert_end(&root, 6);
	// ft_insert_end(&root, -2);

	ft_insert_end(&root, 1);
	ft_insert_end(&root, 2);
	ft_insert_end(&root, 3);
	ft_insert_end(&root, 4);

	ft_insert_end(&root, 6);


	// ft_add_after(root->next, 3);

	t_list *new = root;
	while (new != NULL)
	{
		if (new->next->content == 6){
			ft_add_after(new, 5);
			break;
		}
		new = new->next;
	}
	

	// ft_add_after(root, 5);


	
	t_list *ptr = root;
	while (ptr != NULL){
		printf("%d\n", ptr->content);
		ptr = ptr->next;
	}
}


// what happining if we write void in memory




// =================================

// void    ra(t_stack **a)
// {
//     t_stack *first;
//     t_stack *lsat;
    
//     if (*a == NULL || (*a)->next == NULL)
//         return;
//     first = *a;
//     *a = first->next;
//     lsat = *a;
//     while ((lsat->next != NULL))
//         lsat = lsat->index;
//     lsat->next = first;
//     first->next = NULL;

//     ft_printf("ra\n");
// }

// void    rb(t_stack **b)
// {
//     t_stack *first;
//     t_stack *last;

//     if (*b == NULL || (*b)->index == NULL)
//         return;
//     first = *b;
//     *b = first->next;

//     last = *b;
//     while (last != NULL)
//         last = last->next;
    
//     last->next = first;
//     first->next = NULL;
//     ft_printf("rb\n");
// }
// void rr(t_stack **a, t_stack **b)
// {
//     if (*a && (*a)->next)
//     {
//         t_stack *first = *a;
//         t_stack *last;

//         *a = first->next;
//         last = *a;
//         while (last->next != NULL)
//             last = last->next;
//         last->next = first;
//         first->next = NULL;
//     }
//     if (*b && (*b)->next)
//     {
//         t_stack *first = *b;
//         t_stack *last;
//         *b = first->next;
//         last = *b;
//         while (last->next != NULL)
//             last = last->next;
//         last->next = first;
//         first->next = NULL;
//     }
//     ft_printf("rr\n");
// }

// ====================================