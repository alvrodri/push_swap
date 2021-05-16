/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:15:19 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/16 13:22:50 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_number(t_list *list)
{
	return (((t_stack *)list->content)->number);
}

void	exec_print(t_data *data, char *str)
{
	if (exec_print_s(data, str))
		return ;
	if (exec_print_p(data, str))
		return ;
	if (exec_print_rrx(data, str))
		return ;
	if (exec_print_rx(data, str))
		return ;
}

void	instruction_add(t_data *data, char *type)
{
	char	*tmp;

	tmp = data->instructions;
	data->instructions = ft_strjoin(tmp, type);
	free(tmp);
}

char	*remove_duplicates(t_data *data, char *type)
{
	char	*string;
	char	*find;
	char	*back;
	char	*tmp;

	string = data->instructions;
	find = ft_strnstr(string, type, ft_strlen(string));
	while (find != NULL)
	{
		*find = '\0';
		back = ft_strdup(find + ft_strlen(type));
		tmp = ft_strjoin(string, back);
		free(back);
		free(string);
		string = tmp;
		find = ft_strnstr(string, type, ft_strlen(string));
	}
	return (string);
}

void	instructions_print(t_data *data)
{
	int		i;
	int		pb;
	int		pa;
	char	**split;

	if (ft_strlen(data->instructions) <= 1)
		return ;
	i = 0;
	data->instructions = remove_duplicates(data, "pa pb");
	data->instructions = remove_duplicates(data, "pb pa");
	split = ft_split(data->instructions, ' ');
	while (split[i])
	{
		if (split[i] && split[i][0] != ' ')
		{
			printf("%s\n", split[i]);
			free(split[i]);
		}
		i++;
	}
	free(split);
}
