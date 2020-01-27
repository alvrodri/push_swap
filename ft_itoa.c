/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:16:17 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/16 13:56:19 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_put_nbr(int i, int n, char *arr)
{
	char	c;
	long	nl;

	nl = n;
	if (nl < 0)
	{
		nl = -nl;
		arr[i] = '-';
		i++;
	}
	if (nl > 9)
	{
		ft_put_nbr(i + 1, nl / 10, arr);
	}
	c = (nl % 10) + '0';
	arr[i] = c;
}

static int		ft_get_length(long n)
{
	long	len;

	len = n < 0 ? 1 : 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}

static	void	ft_strrev(char *s, int len)
{
	char	c;
	int		i;
	int		j;

	i = *s == '-' ? 0 : -1;
	j = len;
	while (++i < --j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

char			*ft_itoa(int n)
{
	char	*arr;

	if (!(arr = malloc(sizeof(char) * ft_get_length(n) + 1)))
		return (NULL);
	ft_put_nbr(0, n, arr);
	ft_strrev(arr, ft_get_length(n));
	arr[ft_get_length(n)] = '\0';
	return (arr);
}
