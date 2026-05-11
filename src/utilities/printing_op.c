/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:54:58 by abrunjes          #+#    #+#             */
/*   Updated: 2026/05/11 20:55:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//printing operations to data->operations list, then print them at the end of the program
void log_op(t_ps *data, t_op op)
{
	insert_at_back(&data->operations, op);
	data->operations_counter += 1;
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
	int op_count= 0;
    if (!data || !data->operations)
    {
        printf(RED"\nNo operations to print.\n"RESET);
        return;
    }
    t_node *tmp = data->operations;
    int size = data->operations_counter;
    while (size-- > 0 && tmp != NULL) // Added tmp != NULL for safety
    {
        printf("%s\n", op_to_str(tmp->num));
		op_count += 1;
		
        tmp = tmp->next;
    }
	// printf(GREEN"\n ~~ %d operations ~~\n", op_count);
}
