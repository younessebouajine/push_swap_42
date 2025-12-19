#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum DataType{
    TYPE_INT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_STRING,
    TYPE_CUSTOM
} DataType;

typedef  struct s_list{
    void *content;
    DataType type;
    struct  s_list *next;
}  Node;

Node *ft_creat_node(void *value, DataType type){
    Node *new_node;
    new_node =  (Node *) malloc (sizeof(Node));
    if (!new_node) return (NULL);

    new_node->content = value;
    new_node->type = type;
    new_node->next = NULL;

    return (new_node);
}

void    ft_add_first(Node **root, void *value, DataType type){
    Node *new_node = ft_creat_node(value, type);

    new_node->next = *root;
    *root = new_node;
}

void    ft_add_end(Node **root, void *value, DataType type){
    Node *new_node = ft_creat_node(value, type);

    if (*root == NULL){
        *root = new_node;
        return;
    }

    Node *ptr = *root;
    while (ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void    ft_add_after(Node *node, void *value, DataType type){
    Node *new_node = ft_creat_node(value, type);

    new_node->next = node->next;
    node->next = new_node;
}

void    ft_deallocate(Node **root, int Free_content){
    Node *ptr = *root;
    while (ptr != NULL){
        Node *tmp = ptr;
        ptr = ptr->next;
        if (Free_content && tmp->content != NULL)
            free (tmp->content);
        free(tmp);
    }
    *root = NULL;
}

void swap_nodes(Node *a, Node *b) {
    void *temp_content = a->content;
    DataType temp_type = a->type;
    
    a->content = b->content;
    a->type = b->type;
    
    b->content = temp_content;
    b->type = temp_type;
}

void bubble_sort(Node **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    
    int swapped;
    Node *current;
    Node *last_unsorted = NULL;
    
    do {
        swapped = 0;
        current = *list;
        
        while (current->next != last_unsorted) {
            if (current->type == TYPE_INT && current->next->type == TYPE_INT) {
                int val1 = *(int*)current->content;
                int val2 = *(int*)current->next->content;
                
                if (val1 > val2) {
                    swap_nodes(current, current->next);
                    swapped = 1;
                }
            } else {
                printf("Warning: Can't compare non-integer types\n");
                return;
            }
            current = current->next;
        }
        last_unsorted = current;
        
    } while (swapped);
}


void ft_print_list(Node **list){
    Node *ptr = *list;

    

    while (ptr != NULL){
        if (ptr->type == TYPE_INT){
            printf("%d ", *(int *)ptr->content);
        }
        else if (ptr->type == TYPE_DOUBLE){
            printf("%f ", *(double *)ptr->content);
        }
        else if (ptr->type == TYPE_CHAR){
            printf("%c ", *(char *)ptr->content);
        }
        else if (ptr->type == TYPE_STRING){
            printf("%s ", (char *)ptr->content);
        }
        else {
            printf("[Unknown Type] ");
        }
        ptr = ptr->next; 
    }
    printf("\n");
}



int main(){
    Node *list;
    list = NULL;
    int *i = malloc(sizeof(int));
    if (!i) exit (1);

    int *a = malloc(sizeof(int));
    if (!a) exit (1);
    *a = 3;

    int *b = malloc(sizeof(int));
    if (!b) exit (1);
    *b = 2;

    int *f = malloc(sizeof(int));
    if (!f) exit (1);
    *f = 4;

    int *y = malloc(sizeof(int));
    if (!y) exit (1);
    *y = 0;
    int *o = malloc(sizeof(int));
    if (!o) exit (1);
    *o = 12;
    double *d = malloc(sizeof(double));
    if (!d) exit (1);
    char *c = malloc(1);
    if (!c) exit (1);
    *i = 4;
    *d = 7.43;
    *c = 'Y';

    // ft_add_end(&list, "Hello", TYPE_STRING);
    // ft_add_end(&list, "World", TYPE_STRING);    
    // ft_add_end(&list, "!", TYPE_STRING);
    ft_add_end(&list, i, TYPE_INT);
    ft_add_end(&list, a, TYPE_INT);
    ft_add_end(&list, b, TYPE_INT);
    ft_add_end(&list, f, TYPE_INT);
    ft_add_end(&list, y, TYPE_INT);
    ft_add_end(&list, o, TYPE_INT);


    ft_print_list(&list);

    ft_deallocate(&list, 0);

    free(i);
    free(d);
    free(c);
    return (0);
}



//  Version 2: Generic Bubble Sort (handles any type):


/*

// Compare function type - you provide this based on type
typedef int (*CompareFunc)(void*, void*, DataType, DataType);

// Example compare function for integers
int compare_ints(void *a, void *b, DataType type_a, DataType type_b) {
    if (type_a == TYPE_INT && type_b == TYPE_INT) {
        return (*(int*)a - *(int*)b);
    }
    return 0;  // Can't compare different types
}

// Generic bubble sort with compare function
void bubble_sort_generic(Node **list, CompareFunc compare) {
    if (list == NULL || *list == NULL || (*list)->next == NULL || compare == NULL)
        return;
    
    int swapped;
    Node *current;
    Node *last_unsorted = NULL;
    
    do {
        swapped = 0;
        current = *list;
        
        while (current->next != last_unsorted) {
            // Use the compare function
            int cmp = compare(current->content, 
                            current->next->content,
                            current->type,
                            current->next->type);
            
            if (cmp > 0) {  // a > b, need to swap
                swap_nodes(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last_unsorted = current;
        
    } while (swapped);
}

*/




// Version 3: SIMPLE - Sort only TYPE_INT nodes:
/*

void bubble_sort_ints_only(Node **list) {
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;
    
    int swapped;
    
    do {
        swapped = 0;
        Node *current = *list;
        Node *prev = NULL;
        
        while (current != NULL && current->next != NULL) {
            // Only compare if both are integers
            if (current->type == TYPE_INT && current->next->type == TYPE_INT) {
                int val1 = *(int*)current->content;
                int val2 = *(int*)current->next->content;
                
                if (val1 > val2) {
                    // Swap the content (not nodes)
                    void *temp_content = current->content;
                    DataType temp_type = current->type;
                    
                    current->content = current->next->content;
                    current->type = current->next->type;
                    
                    current->next->content = temp_content;
                    current->next->type = temp_type;
                    
                    swapped = 1;
                }
            }
            // Move to next pair
            current = current->next;
        }
        
    } while (swapped);
}*/ 


// test program 

/*

int main() {
    Node *list = NULL;
    
    // Create a list of integers to sort
    int values[] = {4, 3, 2, 4, 0, 12};
    
    // Add integers to list
    for (int i = 0; i < 6; i++) {
        int *val = malloc(sizeof(int));
        *val = values[i];
        ft_add_end(&list, val, TYPE_INT);
    }
    
    printf("Before sorting: ");
    ft_print_list(&list);
    
    // Sort it
    bubble_sort_ints_only(&list);
    
    printf("After sorting:  ");
    ft_print_list(&list);
    
    // Clean up
    ft_deallocate(&list, 1);  // 1 = free content too
    
    return 0;
}

*/