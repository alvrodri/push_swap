/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alvaro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:37:41 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/05 19:44:03 by alvrodri         ###   ########.fr       */
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
	int		*ranges;
	int		num;
	int 	rest;

	num = size / n;
	rest = size % n;
	ranges = malloc(sizeof(int) * (n * 2));
	ranges[0] = numbers[0];
	ranges[1] = numbers[num - 1];
	ranges[2] = numbers[num];
	ranges[3] = numbers[num * 2 - 1];
	ranges[4] = numbers[num * 2];
	ranges[5] = numbers[num * 3 - 1];
	ranges[6] = numbers[num * 3];
	ranges[7] = numbers[num * 4 - 1];
	ranges[8] = numbers[num * 4];
	ranges[9] = numbers[num * 5 - 1];
	return (ranges);
}

void	pass_better_to_b(t_data *data. int x, int y)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;

	aux = data->a;
	while (aux)
	{

		aux = aux->next;
	}
}

void	pass_to_b(t_data *data, int x, int y)
{
	t_list	*aux;

	aux = data->a;
	while (aux)
	{
		if (aux >= x && aux <= y)
		{
			pass_better_to_b(data, x, y);
			return (pass_to_b(data, x, y));
		}
		aux = aux->next;
	}
}

void	sort_one_hundred(t_data *data)
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
	ranges = get_ranges(data, sorted, ft_lstsize(data->a), 5);
}
