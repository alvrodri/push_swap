/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:02:43 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/17 10:51:24 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;
	size_t			j;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	j = 0;
	if (n == 0)
		return (j);
	while ((ss1[i] == ss2[i] && ss1[i] != '\0') && i < n)
		i++;
	if (i == n)
		i--;
	j = ss1[i] - ss2[i];
	return (j);
}
