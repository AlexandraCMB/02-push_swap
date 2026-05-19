/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:44:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/19 14:39:23 by abrunjes         ###   ########.fr       */
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

//ALGORITHMS
//main_algo
void		butterfly_sort(t_ps *data);
//manual_sort
void		sort(t_ps *data);
void		sort_three(t_ps *data);
void		sort_four(t_ps *data);
void		sort_five(t_ps *data);

//OPERATIONS
void		push(t_node **stack_from, t_node **stack_to);
void		push_a(t_ps *data);
void		push_b(t_ps *data);
void		rev_rot(t_node **stack);
void		rev_rot_a(t_ps *data);
void		rev_rot_b(t_ps *data);
void		rot(t_node **stack);
void		rot_a(t_ps *data);
void		rot_b(t_ps *data);
void		swap(t_node **stack);
void		swap_a(t_ps *data);
void		swap_b(t_ps *data);

//UTILITES
//assigning_indices
void		create_indices(t_ps *data);
//check_inputs
void		check_inputs(int argc, char **argv);
//check_inputs2
int			no_num_found(char *str);
//freeing and exiting
void		free_split(char **arg_v);
void		free_all(t_ps *data);
void		exit_message(int x);
//intitialisng
void		pars_inputs(t_ps *data, int argc, char **argv);
//linked_list.c
t_node		*insert_at_back(t_node **head, int num);
t_node		*init_stack( char **args);
t_node		*insert_at_beginning(t_node **head, t_node *newnode);
void		remove_next_node(t_node *node);
//optimisation.c
void		list_optimisation(t_ps *data);
//printing_op.c
void		log_op(t_ps *data, t_op op);
void		print_ops(t_ps *data);

#endif
