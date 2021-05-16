/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:36:30 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/16 13:30:39 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	split_free(char	**split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	check_duplicates(t_data *data)
{
	t_list	*curr;
	t_list	*aux;

	curr = data->a;
	while (curr)
	{
		aux = data->a;
		while (aux)
		{
			if (((t_stack *)aux->content)->number == ((t_stack *)curr->content)
				->number && (aux != curr))
				ft_exit(data, printf("'%d' is duplicated.\n",
						((t_stack *)curr->content)->number));
			aux = aux->next;
		}
		curr = curr->next;
	}
}

void	allocate_number(t_data *data, int number)
{
	t_list	*list;
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->number = number;
	list = ft_lstnew(stack);
	if (data->a == NULL)
		data->a = list;
	else
		ft_lstadd_back(&data->a, list);
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
			if (is_number(split[j]))
				allocate_number(data, ft_atoi(split[j]));
			else
				ft_exit(data, printf("'%s' is not a number.\n", split[j]));
			j++;
		}
		split_free(split);
		i++;
	}
	if (ft_lstsize(data->a) <= 0)
		ft_exit(data, printf("You have to input at least one number.\n"));
	check_duplicates(data);
}
