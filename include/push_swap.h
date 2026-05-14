/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:44:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/14 14:18:15 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

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
	int				num;
	size_t			idx;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//Struct containing both stacks and operation list 
typedef struct s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*operations;
	size_t	stack_a_size;
	size_t	stack_b_size;
	size_t	operations_counter;
	size_t	size_of_list;
}			t_ps;

//MAIN.C
void		push_swap(t_ps *data);

//OPERATIONS
void		swap(t_node **stack);
void		swap_a(t_ps *data);
void		swap_b(t_ps *data);
void		push(t_node **stack_from, t_node **stack_to);
void		push_a(t_ps *data);
void		push_b(t_ps *data);
void		rot(t_node **stack);
void		rot_a(t_ps *data);
void		rot_b(t_ps *data);
void		rev_rot(t_node **stack);
void		rev_rot_a(t_ps *data);
void		rev_rot_b(t_ps *data);

//UTILITES
//linked_list.c
//STATIC t_node		*create_node(int num);
t_node		*insert_at_back(t_node **head, int num);
t_node		*init_stack( char **args);
t_node		*insert_at_beginning(t_node **head, t_node *newnode);
void		remove_next_node(t_node *node);

//assigning_indices
void		create_indices(t_ps *data);
void		assign_indices(t_node *stack, int *arr, int len);
void		bubble_sort(int *arr, int len);
int			bubble_sort_in_order(int *arr, int len);
//printing_op.c
void		log_op(t_ps *data, t_op op);
const char	*op_to_str(t_op op);
void		print_ops(t_ps *data);
//check_inputs
void		check_inputs(int argc, char **argv);
int			invalid_input(char **tmp);
int			input_checker(char *str);
int			duplicates_in_input(char **tmp);
int			int_overflow(long int num);
void		exit_message(int x);

//freeing and exiting
void		free_nodes(t_node *stack);
void		free_split(char **arg_v);
void		free_all(t_ps *data);
//intitialisng
void		pars_inputs(t_ps *data, int argc, char **argv);
void		initialise_data(t_ps *data, int argc, char **arg_v);


//optimisation.c
void		list_optimisation(t_ps *data);
int			operation_pair_check( t_node *operation);


//ALGORITHMS
//manual_sort
void		sort(t_ps *data);
void		sort_three(t_ps *data);
void		sort_four(t_ps *data);

void		sort_five(t_ps *data);
int			max_in_stack(t_node *stack, size_t idx);
int			min_in_stack(t_node *stack, size_t idx);
int			stack_in_order(t_node *stack);
//main_algo
size_t		ft_sqrt(size_t nb);
void		chunk_sort(t_ps *data);
void		push_back_from_b(t_ps *data);
size_t		cost_to_top_b(t_ps *data, size_t num_in_list);
void		push_back_from_b(t_ps *data);

#endif
