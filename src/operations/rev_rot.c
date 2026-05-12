/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/12 14:51:51 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//REVERSE ROTATIO
void	rev_rot(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->prev;
	return ;
}

void	rev_rot_a(t_ps *data)
{
	rev_rot(&data->stack_a);
	log_op(data, RRA);
	return ;
}

void	rev_rot_b(t_ps *data)
{
	rev_rot(&data->stack_b);
	log_op(data, RRB);
	return ;
}
