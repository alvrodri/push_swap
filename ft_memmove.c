/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:16:54 by alvrodri          #+#    #+#             */
/*   Updated: 2020/01/17 10:43:25 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	dst1 = (unsigned char *)dst;
	src1 = (const unsigned char *)src;
	if (dst1 == src1)
		return (dst);
	else if (dst1 > src1)
	{
		src1 = src1 + len - 1;
		dst1 = dst1 + len - 1;
		while (len > 0)
		{
			*dst1 = *src1;
			dst1--;
			src1--;
			len--;
		}
	}
	else
		dst = ft_memcpy(dst1, src1, len);
	return (dst);
}
