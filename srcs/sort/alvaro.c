/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alvaro.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:37:41 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/06 17:06:51 by alvrodri         ###   ########.fr       */
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

int		instructions_to_b(t_data *data, int n)
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

void	pass_to_b_fr(t_data *data, t_list *elem)
{
	t_list *aux;

	aux = data->a;
	while (aux)
	{
		if (aux == elem)
		{
			/* hacer que lo pase optimizadamente
			 * basicamente hacer ra si esta de la mitad para arriba
			 * o rra si está de la mitad para abajo.. lazy..
			 */
			while (data->a != elem)
				exec_print(data, "ra");
			break ;
		}
		aux = aux->next;
	}
	exec_print(data, "pb");
	if (data->b && data->b->next && data->b->next->next && get_number(data->b)
		< get_number(data->b->next) && get_number(data->b->next) > get_number(data->b->next->next))
		exec_print(data, "sb");
	if (data->b && data->b->next && get_number(data->b->next) > get_number(data->b))
		exec_print(data, "rb");
	while (data->b->next && get_number(data->b) < get_number(data->b->next))
		exec_print(data, "rb");
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
	if (!second || instructions_to_b(data, get_number(first))
		< instructions_to_b(data, get_number(second)))
	{
		pass_to_b_fr(data, first);
	}
	else if (second)
		pass_to_b_fr(data, second);
	else
		;
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
	pass_to_b(data, ranges[0], ranges[1]);
	pass_to_b(data, ranges[2], ranges[3]);
	pass_to_b(data, ranges[4], ranges[5]);
	/*pass_to_b(data, ranges[6], ranges[7]);
	pass_to_b(data, ranges[8], ranges[9]);*/
	aux = data->b;
	while (aux)
	{
		if (aux->next && get_number(aux) < get_number(aux->next))
			exec_print(data, "sb");
		exec_print(data, "pa");
		aux = aux->next;
	}
}
