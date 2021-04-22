/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instruction.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:59:40 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 19:59:03 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	rra(t_data *data)
{
	t_list	*aux;
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(data->a) <= 1)
		return ;
	last = data->a;
	while (last)
	{
		if (last->next->next == NULL)
			break ;
		last = last->next;
	}
	first = ft_lstlast(data->a);
	aux = data->a;
	data->a = first;
	data->a->next = aux;
	aux = data->a;
	while (aux)
	{
		if (aux == last)
			aux->next = NULL;
		aux = aux->next;
	}
}

void	rra(t_data *data)
{
	t_list	*aux;
	t_list	*first;
	t_list	*last;

	if (ft_lstsize(data->a) <= 1)
		return ;
	last = data->a;
	while (last)
	{
		if (last->next->next == NULL)
			break ;
		last = last->next;
	}
	first = ft_lstlast(data->a);
	aux = data->a;
	data->a = first;
	data->a->next = aux;
	aux = data->a;
	while (aux)
	{
		if (aux == last)
			aux->next = NULL;
		aux = aux->next;
	}
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
