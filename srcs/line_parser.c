/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:49:30 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/23 16:32:48 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_instruction(char *str)
{
	if ((ft_strnstr(str, "pa", 2)
		|| ft_strnstr(str, "pb", 2)) && ft_strlen(str) == 2)
		return (1);
	if ((ft_strnstr(str, "sa", 2)
		|| ft_strnstr(str, "sb", 2)
		|| ft_strnstr(str, "ss", 2)) && ft_strlen(str) == 2)
		return (1);
	if ((ft_strnstr(str, "ra", 2)
		|| ft_strnstr(str, "rb", 2)
		|| ft_strnstr(str, "rr", 2)) && ft_strlen(str) == 2)
		return (1);
	if ((ft_strnstr(str, "rra", 3)
		|| ft_strnstr(str, "rrb", 3)
		|| ft_strnstr(str, "rrr", 3)) && ft_strlen(str) == 3)
		return (1);
	return (0);
}

void	execute_instruction(t_data *data)
{
	char	*str;

	str = data->line;
	if (ft_strnstr(str, "sa", 2))
		sa(data);
	if (ft_strnstr(str, "sb", 2))
		sb(data);
	if (ft_strnstr(str, "ss", 2))
		ss(data);
	if (ft_strnstr(str, "pa", 2))
		pa(data);
	if (ft_strnstr(str, "pb", 2))
		pb(data);
	if (ft_strnstr(str, "ra", 2))
		ra(data);
	if (ft_strnstr(str, "rb", 2))
		rb(data);
	if (ft_strnstr(str, "rr", 2))
		rr(data);
	if (ft_strnstr(str, "rra", 3))
		rra(data);
	if (ft_strnstr(str, "rrb", 3))
		rrb(data);
	if (ft_strnstr(str, "rrr", 3))
		rrr(data);
}

void	parse_line(t_data *data)
{
	int	read;

	read = get_next_line(0, &data->line);
	while (read)
	{
		if (!is_instruction(data->line))
			ft_exit(data, printf("'%s' is not a valid instruction.\n", data->line));
		execute_instruction(data);
		free(data->line);
		read = get_next_line(0, &data->line);
	}
	if (check_order(data))
		printf("OK\n");
	else
		printf("KO\n");
}
