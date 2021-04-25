/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:08:33 by alvaro            #+#    #+#             */
/*   Updated: 2021/04/25 11:10:08 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
