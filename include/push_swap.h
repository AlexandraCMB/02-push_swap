/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:44:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/10 12:51:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//man console_codes
# define RED   "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW   "\033[33m"
# define BLUE  "\033[34m"
# define PURP  "\033[35m"
# define TURQ   "\033[36m"
# define BROWN   "\033[37m"

# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <limits.h>

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
	size_t			chunk;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//struct containing both stacks and operation list 
typedef struct s_ps
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*operations;
	size_t	stack_a_size;
	size_t	stack_b_size;
	size_t	operations_counter;
	size_t	size_of_list;
	size_t	size_of_chunk;
	size_t	number_of_chunks;

}			t_ps;

//MAIN.C
int 		stack_len(t_node *stack);
int 		print_stacks(t_ps *data);

// /OPERATIONS/*.c
//swaps
void		swap(t_node **stack);
void		swap_a(t_ps *data);
void		swap_b(t_ps *data);
void		swap_both(t_ps *data);
//pushes
void		push(t_node **stack_from, t_node **stack_to);
void		push_a(t_ps *data);
void		push_b(t_ps *data);
//rotates up
void		rot(t_node **stack);
void		rot_a(t_ps *data);
void		rot_b(t_ps *data);
void		rot_both(t_ps *data);
//rotates down
void		rev_rot(t_node **stack);
void		rev_rot_a(t_ps *data);
void		rev_rot_b(t_ps *data);
void		rot_both(t_ps *data);

//UTILITES/*.c
//linked_list.c
t_node		*create_node(int num);
t_node		*insert_at_back(t_node **head, int num);
t_node		*init_stack(int argc, char **argv);
t_node		*insert_at_beginning(t_node **head, t_node *newnode);
void		remove_next_node(t_node *node);

//assigning_indices
void		create_indices(t_ps *data);
void		assign_indices(t_node *stack, int *arr, int len);
void		bubble_sort(int *arr, int len);
int			in_order(int *arr, int len);
//printing_op.c
void		log_op(t_ps *data, t_op op);
const char	*op_to_str(t_op op);
void		print_ops(t_ps *data);
//input_checker.c
void		input_checker(char *str);
void int_overflow(long int num);
//chunk_sort.c
void		number_of_chunks(t_ps *data);
void assign_chunk_numbers(t_ps *data);
//freeing.c
void		free_nodes(t_node *stack);
//optimisation.c
void		list_optimisation(t_ps *data);
int			operation_pair_check( t_node *operation);





//ALGORITHMS/*.c
//manual_sort.c
void		sort(t_ps *data);
void		sort_three(t_ps *data);
void		sort_five(t_ps *data);
int max_in_stack(t_node *stack, size_t idx);
int min_in_stack(t_node *stack, size_t idx);
int stack_in_order(t_node *stack);
//main_algo.c
void chunk_sort(t_ps *data);
void push_back_from_b(t_ps* data);
int cost_to_top_b(t_ps *data, size_t num_in_list);
void optimised_next_a_to_top(t_ps* data);
int cost_to_top_a(t_ps *data, size_t num_in_list);



void push_back_from_b(t_ps* data);

int cost_to_top_a(t_ps *data, size_t num_in_list);


//LIBFT/*.c
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);

#endif
