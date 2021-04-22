/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:44 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 19:03:02 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

	parse_args(&data, argv + 1);
	rra(&data);
	stack_print(data.a);
	list_free(&data);
	system("leaks a.out");
	return (0);
}
