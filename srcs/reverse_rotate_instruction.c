/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:59:40 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/24 11:46:42 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * curr -> 1
 * last -> 1
 *
 * prev -> 1
 * last -> 2
 *
 * last->next (2) = 1
 * prev->next (1) = NULL (porque si no se hace un infinite loop)
 */

void	rra(t_data *data)
{
	t_list	*last;
	t_list	*prev;
	t_list	*curr;

	if (!data->a || ft_lstsize(data->a) <= 1)
		return ;
	curr = data->a;
	last = curr;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = curr;
	prev->next = NULL;
	data->a = last;
}

void	rrb(t_data *data)
{
	t_list	*last;
	t_list	*prev;
	t_list	*curr;

	if (!data->b || ft_lstsize(data->b) <= 1)
		return ;
	curr = data->b;
	last = curr;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = curr;
	prev->next = NULL;
	data->b = last;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
