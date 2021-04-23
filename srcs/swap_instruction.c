/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:20:55 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/23 16:32:44 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_data *data)
{
	int	number;

	if (ft_lstsize(data->a) <= 1)
		return ;
	number = ((t_stack *)data->a->next->content)->number;
	((t_stack *)data->a->next->content)->number
	= ((t_stack *)data->a->content)->number;
	((t_stack *)data->a->content)->number = number;
}

void	sb(t_data *data)
{
	int	number;

	if (ft_lstsize(data->b) <= 1)
		return ;
	number = ((t_stack *)data->b->next->content)->number;
	((t_stack *)data->b->next->content)->number
	= ((t_stack *)data->b->content)->number;
	((t_stack *)data->b->content)->number = number;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
