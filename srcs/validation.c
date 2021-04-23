/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:38:14 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/23 11:47:47 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_order(t_data *data)
{
	t_list	*curr;
	t_list	*last;

	curr = data->a;
	last = data->a;
	while (curr)
	{
		if (((t_stack *)last->content)->number
			> ((t_stack *)curr->content)->number)
			return (0);
		last = curr;
		curr = curr->next;
	}
	return (1);
}
