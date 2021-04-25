/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:05:58 by alvaro            #+#    #+#             */
/*   Updated: 2021/04/25 15:02:35 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	list_free(t_data *data)
{
	t_list	*curr;

	curr = data->a;
	while (curr)
	{
		free((t_stack *)curr->content);
		free(curr);
		curr = curr->next;
	}
	curr = data->b;
	while (curr)
	{
		free((t_stack *)curr->content);
		free(curr);
		curr = curr->next;
	}
}

void	move_smallest_to_b(t_data *data)
{
	int	smallest;

	smallest = smallest_num_in_stack(data->a);
	if (get_number(data->a) == smallest)
		exec_print(data, "pb");
	else if (get_number(ft_lstlast(data->a)) == smallest)
	{
		exec_print(data, "rra");
		exec_print(data, "pb");
	}
	else if (get_number(data->a->next) == smallest)
	{
		exec_print(data, "sa");
		exec_print(data, "pb");
	}
	else
	{
		while (get_number(data->a) != smallest)
			exec_print(data, "ra");
		exec_print(data, "pb");
	}
}

int		smallest_num_in_stack(t_list *list)
{
	int	number;

	number = get_number(list);
	while (list)
	{
		if (get_number(list) < number)
			number = get_number(list);
		list = list->next;
	}
	return (number);
}

void	ft_exit(t_data *data, int status)
{
	list_free(data);
	exit(status);
}

