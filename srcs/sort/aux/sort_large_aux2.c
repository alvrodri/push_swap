/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_aux2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:59:02 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 09:03:14 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	*get_ranges(t_data *data, int *numbers, int size, int n)
{
	int	*ranges;
	int	num;
	int	rest;
	int	i;
	int	j;

	num = size / n;
	rest = size % n;
	ranges = malloc(sizeof(int) * (n * 2));
	ranges[0] = numbers[0];
	i = 1;
	j = 1;
	while (i < n * 2 - 1)
	{
		ranges[i] = numbers[(num * j) - 1];
		ranges[i + 1] = numbers[num * j];
		i += 2;
		j++;
	}
	return (ranges);
}

int	instructions_to_b(t_data *data, int n)
{
	t_list	*aux;
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(data->a);
	aux = data->a;
	while (aux)
	{
		if (get_number(aux) == n)
			return (size - i + 1);
		i++;
		aux = aux->next;
	}
	return (1);
}

void	while_move_number_to_stack_b(t_data *data, int dir, int n)
{
	while (get_number(data->a) != n)
	{
		if (dir)
			exec_print(data, "ra ");
		else
			exec_print(data, "rra ");
	}
}

void	move_number_to_stack_b(t_data *data, int n)
{
	t_list	*aux;
	int		dir;
	int		i;

	if (!data->a)
		return ;
	aux = data->a;
	dir = get_dir_closest_to_top(n, &data->a);
	i = 0;
	while (aux)
	{
		if (get_number(aux) == n)
		{
			while_move_number_to_stack_b(data, dir, n);
			exec_print(data, "pb ");
			break ;
		}
		aux = aux->next;
		i++;
	}
}

void	what_number_to_move_to_b(t_data *data, t_list *first, t_list *second)
{
	if (!second || instructions_to_b(data, get_number(first))
		< instructions_to_b(data, get_number(second)))
		move_number_to_stack_b(data, get_number(first));
	else if (second)
		move_number_to_stack_b(data, get_number(second));
	else
		return ;
}
