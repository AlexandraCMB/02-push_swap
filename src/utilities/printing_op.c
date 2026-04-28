/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrunjes <abrunjes@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:54:58 by abrunjes          #+#    #+#             */
/*   Updated: 2026/04/28 12:00:26 by abrunjes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//printing operations to data->operations list, then print them at the end of the program
void log_op(t_ps *data, t_op op)
{
	insert_at_back(&data->operations, op);
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
    // Guard: Check if data or operations is NULL
    if (!data || !data->operations)
    {
        printf("No operations to print.\n");
        return;
    }
    t_node *tmp = data->operations;
    int size = data->list_size;
    // Now it's safe to access tmp->num
    while (size-- > 0 && tmp != NULL) // Added tmp != NULL for safety
    {
        printf("%s\n", op_to_str(tmp->num));
        tmp = tmp->next;
    }
}
// void print_ops(t_ps *data)
// {
// 	t_node *tmp = data->operations;
// 	int size = data->list_size;
// 	printf("data->operation->num is %d\n", tmp->num);
// 	while (size-- > 0)
// 	{
// 		printf("%s\n", op_to_str(tmp->num));
// 		tmp = tmp->next;
// 	}
// 	return;
// }