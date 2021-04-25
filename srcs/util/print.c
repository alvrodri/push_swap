/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:15:19 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/25 19:53:47 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_number(t_list *list)
{
	return (((t_stack *)list->content)->number);
}

void	exec_print(t_data *data, char *str)
{
	if (ft_strnstr(str, "sa", 2))
	{
		sa(data);
		instruction_add(data, "sa ");
	}
	else if (ft_strnstr(str, "sb", 2))
	{
		sb(data);
		instruction_add(data, "sb ");
	}
	else if (ft_strnstr(str, "ss", 2))
	{
		ss(data);
		instruction_add(data, "ss ");
	}
	else if (ft_strnstr(str, "pa", 2))
	{
		pa(data);
		instruction_add(data, "pa ");
	}
	else if (ft_strnstr(str, "pb", 2))
	{
		pb(data);
		instruction_add(data, "pb ");
	}
	else if (ft_strnstr(str, "rra", 3))
	{
		rra(data);
		instruction_add(data, "rra ");
	}
	else if (ft_strnstr(str, "rrb", 3))
	{
		rrb(data);
		instruction_add(data, "rrb ");
	}
	else if (ft_strnstr(str, "rrr", 3))
	{
		rrr(data);
		instruction_add(data, "rrr ");
	}
	else if (ft_strnstr(str, "ra", 2))
	{
		ra(data);
		instruction_add(data, "ra ");
	}
	else if (ft_strnstr(str, "rb", 2))
	{
		rb(data);
		instruction_add(data, "rb ");
	}
	else if (ft_strnstr(str, "rr", 2))
	{
		rr(data);
		instruction_add(data, "rr ");
	}
}

void	instruction_add(t_data *data, char *type)
{
	char	*tmp;

	tmp = data->instructions;
	data->instructions = ft_strjoin(tmp, type);
	free(tmp);
}

void	instructions_print(t_data *data)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(data->instructions, ' ');
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
}

void	stack_print(t_list *list)
{
	t_stack	*stack;
	t_list	*curr;

	if (!list)
		return ;
	curr = list;
	while (curr)
	{
		stack = (t_stack *)curr->content;
		printf("%d\n", stack->number);
		curr = curr->next;
	}
	printf("------\n");
}
