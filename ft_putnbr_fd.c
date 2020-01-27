/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:16:35 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/09 13:19:59 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long lnb;
	char c;

	lnb = n;
	if (lnb < 0)
	{
		lnb = -lnb;
		write(fd, "-", 1);
	}
	if (lnb > 9)
	{
		ft_putnbr_fd(lnb / 10, fd);
		ft_putnbr_fd(lnb % 10, fd);
	}
	else
	{
		c = lnb + '0';
		write(fd, &c, 1);
	}
}
