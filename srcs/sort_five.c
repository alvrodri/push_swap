/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:05:34 by alvaro            #+#    #+#             */
/*   Updated: 2021/04/25 11:46:38 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * Maximum actions to pass: 12
 *
 * Move the first two numbers from the top of stack a and move them to stack b
 * then bring them back when the three numbers of stack a are sorted using
 * the sort_three algorithm used previously.
 */

int		is_largest_num(t_list *list, t_list *check)
{
	while (list)
	{
		if (get_number(list) > get_number(check) && list != check)
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort_four(t_data *data)
{
	move_smallest_to_b(data);
	sort_three(data);
	exec_print(data, "pa");
}

void	sort_five(t_data *data)
{
	if (check_order(data))
		return ;
	if (ft_lstsize(data->a) == 4)
		sort_four(data);
	else
	{
		move_smallest_to_b(data);
		sort_four(data);
		exec_print(data, "pa");
	}
/*	exec_print(data, "pb");
	exec_print(data, "pb");
	sort_three(data);
	exec_print(data, "pa");
	if (is_largest_num(data->a, data->a))
		exec_print(data, "ra");
	exec_print(data, "pa");
	if (is_largest_num(data->a, data->a))
		exec_print(data, "ra");*/
}
