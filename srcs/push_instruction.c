/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:11:39 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/23 16:42:33 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_data *data)
{
	t_list	*aux_a;
	t_list	*aux_b;

	if (ft_lstsize(data->b) <= 0)
		return ;
	aux_a = data->a;
	aux_b = data->b->next;
	data->a = data->b;
	data->a->next = aux_a;
	data->b = aux_b->next;
}

void	pb(t_data *data)
{
	t_list	*aux_a;
	t_list	*aux_b;

	if (ft_lstsize(data->a) <= 0)
		return ;
	aux_a = data->a->next;
	aux_b = data->b;
	data->b = data->a;
	data->b->next = aux_b;
	data->a = aux_a;
}
