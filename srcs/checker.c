/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:44 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 22:55:15 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_free(t_data *data)
{
	t_list	*curr;

	curr = data->a;
	while (curr)
	{
		free((t_stack *)curr->content);
		free(curr);
		curr = curr->next;
	}
	curr = data->b;
	while (curr)
	{
		free((t_stack *)curr->content);
		free(curr);
		curr = curr->next;
	}
}

void	ft_exit(t_data *data, int status)
{
	list_free(data);
	exit(status);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	parse_args(&data, argv + 1);
	list_free(&data);
	return (0);
}
