#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Ad hoc function to free a stack
*/

void	free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void free_stacks(t_node **stack_a, t_node **stack_b) {
    free_stack(stack_a);
    free_stack(stack_b);
}

void error_free(t_node **stack, const char *error_message) {
    if (stack != NULL) {
        free_stack(stack);  // Free the stack to prevent memory leaks
    }

    if (error_message != NULL) {
        write(2, error_message, strlen(error_message));
    } else {
        write(2, "Error\n", 6);
    }

    exit(1);
}
/*
 * Check if there are some syntax errors
*/
int	syntax_error(char *str)
{
	if (!(*str== '+'
			|| *str== '-'
			|| (*str>= '0' && *str<= '9')))
		return (1);
	if ((*str== '+'|| *str== '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str>= '0' && *str<= '9'))
			return (1);
	}
	return (0);
}

/*
 * Loop into the stack for some repetition
*/
int	error_repetition(t_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}