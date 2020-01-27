/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:08:25 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:57:14 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(mem = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = s[i + start];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
