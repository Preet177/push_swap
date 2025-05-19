#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
    struct s_node   *prev;
}					t_node;

//Source codes go here
void swap_a(t_node **a);

// Add these to your header file
void rotate(t_node **node);
void rotate_a(t_node **a);

void reverse_rotate(t_node **node);
void reverse_rotate_a(t_node **a);

void push(t_node **src, t_node **dst);
void push_a(t_node **a, t_node **b);
void push_b(t_node **a, t_node **b);

void init_stacks(int *nums, int num_count, t_node **a, t_node **b);
void radix_sort(t_node **stack_a, t_node **stack_b);
void sort_three(t_node **a);
void sort_fourfive(t_node **stack_a, t_node **stack_b);
char **ft_split(char *str, char c);
int stack_len(t_node *node);
//static long	ft_atol(const char *str);

void free_stacks(t_node **stack_a, t_node **stack_b);
int	syntax_error(char *str);
int	error_repetition(t_node *a, int nbr);
void error_free(t_node **stack, const char *error_message);
void	free_stack(t_node **stack);

int compare_ints(const void *a, const void *b);
void rank_numbers(int *nums, int size);
int *extract_numbers(char **argv, int *size);


#endif