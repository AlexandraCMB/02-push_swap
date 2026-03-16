/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:44:25 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:35:41 by abrunjes         ###   ########.fr       */
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

//Structure of doubly linked list s_structure t_type
typedef struct s_node
{
	int 			data;
	size_t			idx;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//PUSH_SWAP.C
int stack_len(t_node *stack);
int print_stacks(t_node *stack_a, t_node *stack_b);

// /OPERATIONS/*.c
//swaps
void	op_sa(t_node **stack, int checker);
void	op_sb(t_node **stack, int checker);
void	op_ss(t_node **stack_a,t_node **stack_b);
//pushes
void	op_pa(t_node **stack_a, t_node **stack_b);
void	op_pb(t_node **stack_a, t_node **stack_b);
//rotates up
void op_ra(t_node **stack, int checker);
void op_rb(t_node **stack, int checker);
void op_rr(t_node **stack_a,t_node **stack_b);
//rotates down
void op_rra(t_node **stack, int checker);
void op_rrb(t_node **stack, int checker);
void op_rrr(t_node **stack_a,t_node **stack_b);

//LINKED LIST UTILITES
t_node *createNode(int data);
t_node *insert_at_back(t_node **head, int data);
t_node *init_stack(int argc, char **argv);
t_node *insert_at_beginning(t_node **head, t_node *newNode);

#endif
