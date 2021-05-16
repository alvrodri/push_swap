/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:05:34 by alvaro            #+#    #+#             */
/*   Updated: 2021/05/16 13:29:16 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_largest_num(t_list *list, t_list *check)
{
	while (list)
	{
		if (get_number(list) > get_number(check) && list != check)
			return (0);
		list = list->next;
	}
	return (1);
}

void	sort_two(t_data *data)
{
	exec_print(data, "sa");
}

void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = get_number(data->a);
	mid = get_number(data->a->next);
	bot = get_number(ft_lstlast(data->a));
	if (top > mid && mid < bot && bot > top)
		exec_print(data, "sa");
	else if (top > mid && mid > bot)
	{
		exec_print(data, "sa");
		exec_print(data, "rra");
	}
	else if (top > bot && mid < bot && bot > mid)
		exec_print(data, "ra");
	else if (top < mid && mid > bot && top < bot)
	{
		exec_print(data, "sa");
		exec_print(data, "ra");
	}
	else if (top < mid && mid > bot)
		exec_print(data, "rra");
}

void	sort_four(t_data *data)
{
	move_smallest_to_b(data);
	sort_three(data);
	exec_print(data, "pa");
}

void	sort_five(t_data *data)
{
	move_smallest_to_b(data);
	sort_four(data);
	exec_print(data, "pa");
}
