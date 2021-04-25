/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:15:19 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/25 11:10:54 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_number(t_list *list)
{
	return (((t_stack *)list->content)->number);
}

void	exec_print(t_data *data, char *str)
{
	if (ft_strnstr(str, "sa", 2))
	{
		sa(data);
		printf("sa\n");
	}
	else if (ft_strnstr(str, "sb", 2))
	{
		sb(data);
		printf("sb\n");
	}
	else if (ft_strnstr(str, "ss", 2))
	{
		ss(data);
		printf("ss\n");
	}
	else if (ft_strnstr(str, "pa", 2))
	{
		pa(data);
		printf("pa\n");
	}
	else if (ft_strnstr(str, "pb", 2))
	{
		pb(data);
		printf("pb\n");
	}
	else if (ft_strnstr(str, "rra", 3))
	{
		rra(data);
		printf("rra\n");
	}
	else if (ft_strnstr(str, "rrb", 3))
	{
		rrb(data);
		printf("rrb\n");
	}
	else if (ft_strnstr(str, "rrr", 3))
	{
		rrr(data);
		printf("rrr\n");
	}
	else if (ft_strnstr(str, "ra", 2))
	{
		ra(data);
		printf("ra\n");
	}
	else if (ft_strnstr(str, "rb", 2))
	{
		rb(data);
		printf("rb\n");
	}
	else if (ft_strnstr(str, "rr", 2))
	{
		rr(data);
		printf("rr\n");
	}
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
