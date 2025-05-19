#include "push_swap.h"

// Function to find the maximum value in the stack
int find_max(t_node *a)
{
    int max_val = a->value;
    t_node *node = a->next;
    while (node != NULL)
    {
        if (node->value > max_val)
        {
            max_val = node->value;
        }
        node = node->next;
    }
    return max_val;
}

void radix_sort(t_node **a, t_node **b) {
    int max_val = find_max(*a);
    int max_bits = 0;
    while ((max_val >> max_bits) > 0)
    {
        max_bits++;
    }

    int bit = 0;
    while (bit < max_bits) 
    {
        int count = stack_len(*a);
        int i = 0;
        while (i < count) 
        {
            t_node *node = *a;
            if ((node->value >> bit) & 1)
            {
                rotate_a(a); // Rotate stack A
            }
             else 
             {
                push_b(a, b); // Push from stack A to stack B
            }
            i++;
        }
        // Move all nodes back to stack A from stack B
        while (*b != NULL) 
        {
            push_a(a, b); // Push from stack B to stack A
        }
        bit++;
    }
}