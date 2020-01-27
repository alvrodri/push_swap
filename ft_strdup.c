/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:44:11 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/17 10:45:46 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		l;

	l = ft_strlen(s1);
	if (!(s2 = malloc(l + 1)))
		return (NULL);
	ft_memcpy(s2, s1, l);
	s2[l] = '\0';
	return (s2);
}
