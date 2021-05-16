/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:37:41 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/16 13:45:46 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static int	get_min_number(t_list *list)
{
	t_list	*aux;
	int		min;

	if (!list)
		return (0);
	min = get_number(list);
	aux = list;
	while (aux)
	{
		if (get_number(aux) < min)
			min = get_number(aux);
		aux = aux->next;
	}
	return (min);
}

int	get_max_number(t_list *list)
{
	t_list	*aux;
	int		max;

	if (!list)
		return (0);
	max = get_number(list);
	aux = list;
	while (aux)
	{
		if (get_number(aux) > max)
			max = get_number(aux);
		aux = aux->next;
	}
	return (max);
}

int	get_dir_closest_to_top(int n, t_list **list)
{
	t_list	*aux;
	int		i;
	int		size;

	if (!*list)
		return (-1);
	i = 0;
	size = ft_lstsize(*list);
	aux = *list;
	while (aux)
	{
		if (get_number(aux) == n)
			break ;
		aux = aux->next;
		i++;
	}
	if (i < size / 2)
		return (1);
	else
		return (0);
}

void	bubble_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

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

void	pass_better_to_b(t_data *data, int x, int y)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;
	int		num;

	aux = data->a;
	first = NULL;
	second = NULL;
	while (aux)
	{
		num = get_number(aux);
		if (num >= x && num <= y)
		{
			if (!first)
				first = aux;
			else
				second = aux;
		}
		aux = aux->next;
	}
	what_number_to_move_to_b(data, first, second);
}

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
