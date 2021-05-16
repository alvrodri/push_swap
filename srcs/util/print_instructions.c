/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:22:25 by alvaro            #+#    #+#             */
/*   Updated: 2021/05/16 13:23:01 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	exec_print_s(t_data *data, char *str)
{
	if (ft_strnstr(str, "sa", 2))
	{
		sa(data);
		instruction_add(data, "sa ");
		return (1);
	}
	else if (ft_strnstr(str, "sb", 2))
	{
		sb(data);
		instruction_add(data, "sb ");
		return (1);
	}
	else if (ft_strnstr(str, "ss", 2))
	{
		ss(data);
		instruction_add(data, "ss ");
		return (1);
	}
	return (0);
}

int	exec_print_p(t_data *data, char *str)
{
	if (ft_strnstr(str, "pa", 2))
	{
		pa(data);
		instruction_add(data, "pa ");
		return (1);
	}
	else if (ft_strnstr(str, "pb", 2))
	{
		pb(data);
		instruction_add(data, "pb ");
		return (1);
	}
	return (0);
}

int	exec_print_rrx(t_data *data, char *str)
{
	if (ft_strnstr(str, "rra", 3))
	{
		rra(data);
		instruction_add(data, "rra ");
		return (1);
	}
	else if (ft_strnstr(str, "rrb", 3))
	{
		rrb(data);
		instruction_add(data, "rrb ");
		return (1);
	}
	else if (ft_strnstr(str, "rrr", 3))
	{
		rrr(data);
		instruction_add(data, "rrr ");
		return (1);
	}
	return (0);
}

int	exec_print_rx(t_data *data, char *str)
{
	if (ft_strnstr(str, "ra", 2))
	{
		ra(data);
		instruction_add(data, "ra ");
		return (1);
	}
	else if (ft_strnstr(str, "rb", 2))
	{
		rb(data);
		instruction_add(data, "rb ");
		return (1);
	}
	else if (ft_strnstr(str, "rr", 2))
	{
		rr(data);
		instruction_add(data, "rr ");
		return (1);
	}
	return (0);
}
