/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:47:48 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 18:59:17 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ra(t_data *data)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->a) <= 1)
		return ;
	last = data->a;
	aux = data->a->next;
	data->a = aux;
	ft_lstlast(data->a)->next = last;
	last->next = NULL;
}

void	rb(t_data *data)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(data->a) <= 1)
		return ;
	last = data->b;
	aux = data->b->next;
	data->b = aux;
	ft_lstlast(data->b)->next = last;
	last->next = NULL;
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
