/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:50:00 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/23 14:00:05 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *aux;

	while (*lst && del)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
