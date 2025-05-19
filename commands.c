#include "push_swap.h"

void push(t_node **dst, t_node **src)
{
	t_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}

void push_a(t_node **a, t_node **b)
{
    push(a, b);
    write (1, "pa\n", 3);
}

void push_b(t_node **a, t_node **b)
{
    push(b, a);
    write (1, "pb\n", 3);
}

void reverse_rotate(t_node **node)
{
    t_node *tmp;
    t_node *tmp2;

    if (*node == NULL || (*node)->next == NULL)
        return;
    tmp = *node;
    while ((*node)->next->next != NULL)
    {
        *node = (*node)->next;
    }
    tmp2 = (*node)->next;
    tmp2->next = tmp;
    (*node)->next = NULL;
    *node = tmp2;
}

void reverse_rotate_a(t_node **a)
{
    reverse_rotate(a);
    write (1, "rra\n", 4);
}

t_node	*find_last_node(t_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	rotate(t_node **stack)
{
	t_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void rotate_a(t_node **a)
{
    rotate(a);
    write (1, "ra\n", 3);
}

void swap(t_node **node)
{
    t_node *tmp;

    if (!*node || (*node)->next == NULL)
        return ;
    tmp = *node;
    *node = (*node)->next;
    tmp->next = (*node)->next;
    (*node)->next = tmp;
}

void swap_a(t_node **a)
{
    swap(a);
    write (1, "sa\n", 3);
}
