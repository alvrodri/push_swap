/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:29:20 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/23 13:59:08 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *node;

	if (new)
	{
		node = *lst;
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
		}
		else
		{
			node = ft_lstlast(*lst);
			node->next = new;
		}
	}
}
