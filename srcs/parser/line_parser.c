/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:49:30 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 08:53:05 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_instruction2(char *str)
{
	if ((ft_strnstr(str, "ra", 2)
			|| ft_strnstr(str, "rb", 2)
			|| ft_strnstr(str, "rr", 2)) && ft_strlen(str) == 2)
	{
		free(str);
		return (1);
	}
	if ((ft_strnstr(str, "rra", 3)
			|| ft_strnstr(str, "rrb", 3)
			|| ft_strnstr(str, "rrr", 3)) && ft_strlen(str) == 3)
	{
		free(str);
		return (1);
	}
	return (0);
}

int	is_instruction(char *str)
{
	if (str[0] == '\0')
		return (0);
	str = ft_strtrim(str, " ");
	if ((ft_strnstr(str, "pa", 2)
			|| ft_strnstr(str, "pb", 2)) && ft_strlen(str) == 2)
	{
		free(str);
		return (1);
	}
	if ((ft_strnstr(str, "sa", 2)
			|| ft_strnstr(str, "sb", 2)
			|| ft_strnstr(str, "ss", 2)) && ft_strlen(str) == 2)
	{
		free(str);
		return (1);
	}
	if (is_instruction2(str))
		return (1);
	free(str);
	return (0);
}

void	execute_instruction(t_data *data)
{
	char	*str;

	str = data->line;
	if (ft_strnstr(str, "sa", 2))
		sa(data);
	else if (ft_strnstr(str, "sb", 2))
		sb(data);
	else if (ft_strnstr(str, "ss", 2))
		ss(data);
	else if (ft_strnstr(str, "pa", 2))
		pa(data);
	else if (ft_strnstr(str, "pb", 2))
		pb(data);
	else if (ft_strnstr(str, "rra", 3))
		rra(data);
	else if (ft_strnstr(str, "rrb", 3))
		rrb(data);
	else if (ft_strnstr(str, "rrr", 3))
		rrr(data);
	else if (ft_strnstr(str, "ra", 2))
		ra(data);
	else if (ft_strnstr(str, "rb", 2))
		rb(data);
	else if (ft_strnstr(str, "rr", 2))
		rr(data);
}

void	parse_line(t_data *data)
{
	int	read;

	read = get_next_line(0, &data->line);
	while (read)
	{
		if (!is_instruction(data->line))
			ft_exit(data, "Error\n");
		execute_instruction(data);
		free(data->line);
		read = get_next_line(0, &data->line);
	}
	if (check_order(data) && ft_lstsize(data->b) <= 0)
		printf("OK\n");
	else
		printf("KO\n");
}
