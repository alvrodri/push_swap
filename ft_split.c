/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:09:09 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/18 16:44:35 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_parts(char const *s, char c)
{
	int i;
	int parts;

	i = 0;
	parts = s[i] != c ? 1 : 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1]) && s[i + 1] != c)
			parts++;
		i++;
	}
	return (parts);
}

static void		ft_allocate_memory(char **arr, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i] != c && s[i] != '\0')
			{
				j++;
				i++;
			}
			if (!(arr[k] = malloc(sizeof(char) * j + 1)))
				return ;
			k++;
		}
		else
			i++;
	}
}

static void		ft_add_parts(char **split, char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				split[j][k] = s[i];
				i++;
				k++;
			}
			split[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	int		parts;

	if (!s)
		return (NULL);
	parts = ft_count_parts(s, c);
	if (!(split = malloc(sizeof(char *) * (parts + 1))))
		return (NULL);
	if (*s == '\0')
	{
		split[0] = NULL;
		return (split);
	}
	ft_allocate_memory(split, s, c);
	ft_add_parts(split, (char *)s, c);
	split[parts] = NULL;
	return (split);
}
