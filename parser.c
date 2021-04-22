/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:30 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/22 16:35:48 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int		is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i != 0 && str[i] == '-')
			return (0);
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void	split_free(char	**split)
{
	int	i;

	i = 0;
	while (split[i++])
		free(split[i]);
	free(split);
}

void	parse_args(t_data *data, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			if (!is_number(split[j]))
				ft_exit(printf("'%s' is not a number.\n", split[j]));
			printf("|%d|\n", ft_atoi(split[j]));
			/*
			 * Agregar a la lista. TODO
			 */
			j++;
		}
		split_free(split);
		i++;
	}
}
