/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:44:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/25 14:55:46 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define C0   "\033[30m"
# define C1   "\033[31m"
# define C2   "\033[32m"
# define C3   "\033[33m"
# define C4   "\033[34m"
# define C5   "\033[35m"
# define C6   "\033[36m"
# define C7   "\033[37m"
# define C8   "\033[38m"
# define C9   "\033[39m"
# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

//Structure of doubly linked list
typedef struct s_node
{
	int			data;
	size_t			idx;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//struct containing list and their sizes
typedef struct s_stack
{
	t_node			*head;
	int 			size;
}					t_stack;

//struct containing both stacks and operation lsit
typedef struct s_ps
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*operations;
}			t_ps;

//MAIN.C
int stack_len(t_node *stack);
int print_stacks(t_ps *data);

// /OPERATIONS/*.c
//swaps
void	swap(t_node **stack);
void	swap_a(t_ps *data);
void	swap_b(t_ps *data);
void	swap_both(t_ps *data);
//pushes
void	push(t_node **stack_from, t_node **stack_to);
void	push_a(t_ps *data);
void	push_b(t_ps *data);
//rotates up
void	rot(t_node **stack);
void	rot_a(t_ps *data);
void	rot_b(t_ps *data);
void	rot_both(t_ps *data);
//rotates down
void	rev_rot(t_node **stack);
void	rev_rot_a(t_ps *data);
void	rev_rot_b(t_ps *data);
void	rot_both(t_ps *data);

//UTILITES
//linked_list.c
t_node	*create_node(int data);
t_node	*insert_at_back(t_node **head, int data);
t_node	*init_stack(int argc, char **argv);
t_node	*insert_at_beginning(t_node **head, t_node *newnode);
void	free_nodes(t_stack *stack);
//assigning_indices
void	create_indices(t_ps *data);
void	assign_indices(t_node *stack, int *arr, int len);
void	bubble_sort(int *arr, int len);
int		in_order(int *arr, int len);
//manual_sorting.c
void	sort(t_ps *data);
void	sort_three(t_ps *data);
//printing_op.c
void log_op(t_ps *data, t_op op);
const char *op_to_str(t_op op);
void print_ops(t_ps *data);


#endif
