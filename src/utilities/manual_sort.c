/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:55:54 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/24 19:40:34 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort(t_ps *data)
{
	size_t len = data->stack_a->size;
	if (len == 2)
	{
		if (data->stack_a->head->data > data->stack_a->head->next->data)
			swap_a(data);
	}
	else if (len == 3)
		sort_three(data);
	else if (len == 4)
		printf("Do sort_four(data) here\n");
	else if (len == 5)
		printf("Do sort_five(data) here\n");
	else
		printf("Do main_algo(data) here\n");
}

void sort_three(t_ps *data)
{
	int first = data->stack_a->head->data;
	int second = data->stack_a->head->next->data;
	int third = data->stack_a->head->next->next->data;

	if (first > second && second < third && first < third)
		swap_a(data);

	else if (first < second && second > third && first > third)
		rev_rot_a(data);
	else if (first > second && second < third && first > third)
		rot_a(data);
	else if (first < second && second > third && first < third)
	{
		rev_rot_a(data);
		swap_a(data);
	}
	else if (first > second && second > third)
	{
		swap_a(data);
		rev_rot_a(data);
	}

}