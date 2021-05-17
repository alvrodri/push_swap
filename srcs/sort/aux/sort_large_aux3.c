/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_aux3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:59:32 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 08:59:46 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	pass_better_to_b(t_data *data, int x, int y)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;
	int		num;

	aux = data->a;
	first = NULL;
	second = NULL;
	while (aux)
	{
		num = get_number(aux);
		if (num >= x && num <= y)
		{
			if (!first)
				first = aux;
			else
				second = aux;
		}
		aux = aux->next;
	}
	what_number_to_move_to_b(data, first, second);
}
