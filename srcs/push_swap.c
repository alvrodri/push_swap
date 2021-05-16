/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:03:46 by alvaro            #+#    #+#             */
/*   Updated: 2021/05/16 13:02:19 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_start(t_data *data)
{
	int	size;

	size = ft_lstsize(data->a);
	if (check_order(data) || size < 2)
		return ;
	else if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size == 4)
		sort_four(data);
	else if (size == 5)
		sort_five(data);
	else
		sort_large(data);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data.a = NULL;
	data.b = NULL;
	data.instructions = ft_strdup(" ");
	parse_args(&data, argv + 1);
	sort_start(&data);
	if (ft_strlen(data.instructions) > 2)
		instructions_print(&data);
	list_free(&data);
	free(data.instructions);
}
