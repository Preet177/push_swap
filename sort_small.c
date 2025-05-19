#include "push_swap.h"

static t_node *find_highest(t_node *stack)
{
    int highest;
    t_node *highest_node;

    if (NULL == stack)
        return NULL;
    highest = INT_MIN;
    while (stack)
    {
        if (stack->value > highest)
        {
            highest = stack->value;
            highest_node = stack;
        }
        stack = stack->next;
    }
    return highest_node;
}

void sort_three(t_node **a)
{
    t_node *highest_node;

    highest_node = find_highest(*a);
    if (*a == highest_node)
        rotate_a(a);
    else if ((*a)->next == highest_node)
        reverse_rotate_a(a);
    if ((*a)->value > (*a)->next->value)
        swap_a(a);
}

static t_node *find_lowest(t_node *stack) {
    int lowest;
    t_node *lowest_node;

    if (NULL == stack)
        return NULL;
    lowest = INT_MAX;
    while (stack) {
        if (stack->value < lowest) {
            lowest = stack->value;
            lowest_node = stack;
        }
        stack = stack->next;
    }
    return lowest_node;
}

void sort_fourfive(t_node **stack_a, t_node **stack_b) {
    int total = stack_len(*stack_a);
    t_node *lowest_node;

    // Move the lowest one or two elements to stack_b
    while (total > 3) {
        lowest_node = find_lowest(*stack_a);
        while (*stack_a != lowest_node) {
            if ((*stack_a)->next == lowest_node)
                swap_a(stack_a);
            else
                rotate_a(stack_a);
        }
        push_b(stack_a, stack_b);
        total--;
    }

    // Sort the remaining three elements in stack_a
    sort_three(stack_a);

    // Move elements back from stack_b to stack_a
    while (*stack_b != NULL) {
        push_a(stack_a, stack_b);
        if ((*stack_a)->value > (*stack_a)->next->value)
            swap_a(stack_a);
    }
}
