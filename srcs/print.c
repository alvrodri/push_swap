/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:15:19 by alvrodri          #+#    #+#             */
/*   Updated: 2021/04/24 11:40:11 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_number(t_list *list)
{
	return (((t_stack *)list->content)->number);
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
