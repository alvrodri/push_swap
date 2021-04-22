/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:20:55 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 22:46:58 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->a) <= 1)
		return ;
	aux = data->a;
	data->a = data->a->next;
	data->a->next = aux;
}

void	sb(t_data *data)
{
	t_list	*aux;

	if (ft_lstsize(data->b) <= 1)
		return ;
	aux = data->b;
	data->b = data->b->next;
	data->b->next = aux;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
