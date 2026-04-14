/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/14 18:34:51 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ROTATION
void	rot(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;

	return ;
}

//RA
void rot_a(t_ps *data)
{
	if (!data->stack_a)
		return ;
	data->stack_a = data->stack_a->next;
	log_op(data, RA);
	return ;
}

//RB
void rot_b(t_ps *data)
{
	if (!data->stack_b)
		return ;
	data->stack_b = data->stack_b->next;
	log_op(data, RB);
	return ;
}

//RA&RB
void rot_both(t_ps *data)
{
	rot_a(data);
	rot_b(data);
	log_op(data, RR);
	return ;
}