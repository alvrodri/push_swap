/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:11:39 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/25 15:09:51 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	if (aux_b)
		data->b = aux_b;
	else
		data->b = NULL;
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
