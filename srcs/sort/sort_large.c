/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:37:41 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 08:59:26 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pass_to_b(t_data *data, int x, int y)
{
	t_list	*aux;

	aux = data->a;
	while (aux)
	{
		if (get_number(aux) >= x && get_number(aux) <= y)
		{
			pass_better_to_b(data, x, y);
			return (pass_to_b(data, x, y));
		}
		aux = aux->next;
	}
}

void	while_move_number_to_stack_a(t_data *data, int dir, int n)
{
	while (get_number(data->b) != n)
	{
		if (dir)
			exec_print(data, "rb ");
		else
			exec_print(data, "rrb ");
	}
}

void	move_number_to_stack_a(t_data *data, int n)
{
	t_list	*aux;
	int		dir;
	int		i;

	if (!data->b)
		return ;
	aux = data->b;
	dir = get_dir_closest_to_top(n, &data->b);
	i = 0;
	while (aux)
	{
		if (get_number(aux) == n)
		{
			while_move_number_to_stack_a(data, dir, n);
			exec_print(data, "pa ");
			break ;
		}
		aux = aux->next;
		i++;
	}
}

void	set_ranges(t_data *data, int **ranges, int *sorted)
{
	int	i;

	i = 0;
	if (ft_lstsize(data->a) > 100)
	{
		*ranges = get_ranges(data, sorted, ft_lstsize(data->a), 12);
		while (i < 24)
		{
			pass_to_b(data, (*ranges)[i], (*ranges)[i + 1]);
			i += 2;
		}
	}
	else
	{
		*ranges = get_ranges(data, sorted, ft_lstsize(data->a), 5);
		while (i < 10)
		{
			pass_to_b(data, (*ranges)[i], (*ranges)[i + 1]);
			i += 2;
		}
	}
}

void	sort_large(t_data *data)
{
	t_list	*aux;
	int		*sorted;
	int		*ranges;

	sorted = malloc(sizeof(int) * ft_lstsize(data->a));
	if (!sorted)
		return ;
	aux = data->a;
	while (aux)
	{
		*sorted = get_number(aux);
		aux = aux->next;
		sorted++;
	}
	sorted -= ft_lstsize(data->a);
	bubble_sort(sorted, ft_lstsize(data->a));
	set_ranges(data, &ranges, sorted);
	while (data->a)
		exec_print(data, "pb ");
	while (data->b)
		move_number_to_stack_a(data, get_max_number(data->b));
	free(sorted);
	free(ranges);
}
