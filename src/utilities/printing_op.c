/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:54:58 by abrunjes          #+#    #+#             */
/*   Updated: 2026/03/25 15:12:18 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void log_op(t_ps *data, t_op op)
{
	insert_at_back(&data->operations->head, op);
	data->operations->size++;
	return;
}

const char *op_to_str(t_op op)
{
	char *ops[11];
	ops[0] = "sa";
	ops[1] = "sb";
	ops[2] = "ss";
	ops[3] = "pa";
	ops[4] = "pb";
	ops[5] = "ra";
	ops[6] = "rb";
	ops[7] = "rr";
	ops[8] = "rra";
	ops[9] = "rrb";
	ops[10] = "rrr";
	return (ops[op]);
}

void print_ops(t_ps *data)
{
	t_node *tmp = data->operations->head;
	int size = data->operations->size;
	while (size-- > 0)
	{
		printf("%s\n", op_to_str(tmp->data));
		tmp = tmp->next;
	}
	return;
}

