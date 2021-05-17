/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_aux1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 08:58:28 by alvrodri          #+#    #+#             */
/*   Updated: 2021/05/17 08:58:47 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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
