/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 13:22:56 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/05 15:43:50 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
 * Buscar el número más pequeño del stack A
 * llevarlo hasta el principio haciendo ra o rra
 * depende de en que mitad está (para hacerlo con el
 * menor número de instrucciones posibles):
 *  · si está de la mitad para arriba se hace: ra
 *  · si está de la mitad para abajo se hace: rra
 */

int		get_min_number(t_data *data)
{
	t_list	*curr;
	int		min;

	min = get_number(data->a);
	curr = data->a;
	while (curr)
	{
		if (get_number(curr) < min)
			min = get_number(curr);
		curr = curr->next;
	}
	return (min);
}

void	move_min_to_b(t_data *data, int i, int dir)
{
	int		num;
	int		j;

	if (!dir)
		num = ft_lstsize(data->a) - i;
	else
		num = i;
	j = 0;
	while (j < num)
	{
		if (dir)
			exec_print(data, "ra ");
		else
			exec_print(data, "rra "); 
		j++;
	}
	exec_print(data, "pb ");
}

void	continue_sort(t_data *data)
{
	t_list	*curr;
	int		min;
	int		half;
	int		i;

	half = ft_lstsize(data->a) / 2;
	curr = data->a;
	min = get_min_number(data);
	i = 0;
	while (curr)
	{
		if (get_number(curr) == min)
		{
			if (i > half)
				move_min_to_b(data, i, 0);
			else
				move_min_to_b(data, i, 1);
			break ;
		}
		curr = curr->next;
		i++;
	}
}

/*void	sort_one_hundred(t_data *data)
{
	while (ft_lstsize(data->a) > 0)
	{
		continue_sort(data);
	}
	while (ft_lstsize(data->b) > 0)
	{
		exec_print(data, "pa ");
	}
}*/
