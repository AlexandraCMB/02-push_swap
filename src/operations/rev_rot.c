/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:38:17 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 13:27:18 by abrunjes         ###   ########.fr       */
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


void rev_rot_a(t_ps *data)
{
	rev_rot(&data->stack_a->head);
	return ;
}

void rev_rot_b(t_ps *data)
{
	rev_rot(&data->stack_b->head);
	return ;
}

void rev_rot_both(t_ps *data)
{
	rev_rot(&data->stack_a->head);
	rev_rot(&data->stack_b->head);
	return ;
}