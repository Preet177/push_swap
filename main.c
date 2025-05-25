#include "push_swap.h"

int stack_len(t_node *node) {
    int count = 0;
    while (node != NULL) {
        count++;
        node = node->next;
    }
    return count;
} 

void print_stack(t_node *stack) {
    printf("Stack: ");
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
} 

void pick_sort(t_node **stack_a, t_node **stack_b, int total) {
    if (total == 2) 
    {
         if (*stack_a && (*stack_a)->next && (*stack_a)->value > (*stack_a)->next->value)
            rotate_a(stack_a); 
    } 
    else if (total == 3) 
    {
        sort_three(stack_a); 
    }
    else if (total == 4 || total == 5)
    {
        sort_fourfive(stack_a, stack_b); 
    }
    else if (total > 5) 
    {
        radix_sort(stack_a, stack_b); 
    }
}

int main(int argc, char **argv) {
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    int *nums = NULL;
    int total = 0;
    char **split_argv = NULL; // Variable to hold the result of ft_split
    int i; // Iterator for the while loop

    if (argc == 1 || (argc == 2 && !argv[1][0])) {
        return 1;
    }
    if (argc == 2) {
        split_argv = ft_split(argv[1], ' '); // Store the result of ft_split
        argv = split_argv; // Assign split_argv to argv for further processing
    }

    nums = extract_numbers(argv + 1, &total); // Skip the program name

    // Free the memory allocated by ft_split using a while loop
    if (split_argv != NULL) {
        i = 0;
        while (split_argv[i] != NULL) {
            free(split_argv[i]);
            i++;
        }
        free(split_argv);
    }

    rank_numbers(nums, total);
    init_stacks(nums, total, &stack_a, &stack_b);
    printf("Initial Stack:\n");
    print_stack(stack_a);
    pick_sort(&stack_a, &stack_b, total);
    printf("Sorted Stack:\n");
    print_stack(stack_a);
    free_stacks(&stack_a, &stack_b);
    free(nums);
    return 0;
}
