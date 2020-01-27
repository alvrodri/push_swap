/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 13:57:59 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/15 13:14:58 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return ((char *)s1);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, 0, end + 1));
}
