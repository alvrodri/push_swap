/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 12:03:46 by alvaro            #+#    #+#             */
/*   Updated: 2021/04/24 12:32:55 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_two(t_data *data)
{
	if (!check_order(data))
		exec_print(data, "sa");
}

void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = get_number(data->a);
	mid = get_number(data->a->next);
	bot = get_number(ft_lstlast(data->a));
	if (top > mid && mid < bot && bot > top)
		return exec_print(data, "sa");
	if (top > mid && mid > bot)
	{
		exec_print(data, "sa");
		return exec_print(data, "rra");
	}
	if (top > bot && mid < bot && bot > mid)
		return exec_print(data, "ra");
	if (top < mid && mid > bot && top < bot)
	{
		exec_print(data, "sa");
		return exec_print(data, "ra");
	}
	if (top < mid && mid > bot)
		return exec_print(data, "rra");
}

void	sort_start(t_data *data)
{
	int	size;

	size = ft_lstsize(data->a);
	if (size < 2)
		return ;
	else if (size == 2)
		sort_two(data);
	else if (size == 3)
		sort_three(data);
	else if (size > 3 && size < 6)
		;//sort_five(data);
	else if (size > 5)
		;//sort_one_hundred(data);
	else
		;//sort_five_hundred(data);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	data.a = NULL;
	data.b = NULL;
	parse_args(&data, argv + 1);
	sort_start(&data);
	list_free(&data);
}
