/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 14:24:54 by abrunjes         ###   ########.fr       */
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
	if (!data->stack_a->head)
		return ;
	data->stack_a->head = data->stack_a->head->next;
	return ;
}

//RB
void rot_b(t_ps *data)
{
	if (!data->stack_b->head)
		return ;
	data->stack_b->head = data->stack_b->head->next;
	return ;
}

//RA&RB
void rot_both(t_ps *data)
{
	rot_a(data);
	rot_b(data);
	return ;
}