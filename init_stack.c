#include "push_swap.h"

// Helper function to append a node to a stack
void append_to_stack(t_node **stack, int value) 
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
     {
        error_free(stack, "Error\n"); // Updated error handling
        return;
    }
    new_node->value = value;
    new_node->next = NULL;
    if (*stack) 
    {
        t_node *last = *stack;
        while (last->next != NULL) 
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->prev = last;
    } 
    else 
    {
        new_node->prev = NULL;
        *stack = new_node;
    }
}

void init_stacks(int *nums, int num_count, t_node **a, t_node **b) 
{
    *a = NULL;
    *b = NULL;

    int i = 0;
    while (i < num_count)
     {
        if (error_repetition(*a, nums[i])) 
        {
            error_free(a, "Error\n");
            return;
        }
        append_to_stack(a, nums[i]);
        i++;
    }
} 