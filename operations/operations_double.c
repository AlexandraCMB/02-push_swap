/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/15 19:42:18 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_ss(t_node **stack_a, t_node **stack_b)
{
	int	checker;

	checker = 0;
	op_sa(stack_a, checker);
	op_sa(stack_b, checker);
	write(1, "ss\n", 4);
	return ;
}

// rr : ra and rb at the same time
void	op_rr(t_node **stack_a, t_node **stack_b)
{
	int	check;

	check = 0;
	op_ra(stack_a, check);
	op_rb(stack_b, check);
	write(1, "rr\n", 3);
	return ;
}

// rrr : rra and rrb at the same time.
void	op_rrr(t_node **stack_a, t_node **stack_b)
{
	int	check;

	check = 0;
	op_ra(stack_a, check);
	op_rb(stack_b, check);
	write(1, "rrr\n", 4);
	return ;
}
