/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:51:54 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/03 21:17:44 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_rev(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dst;
	s = (char *)src;
	i = len;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL || src == NULL)
		return (NULL);
	if (src == dst)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		ft_memcpy_rev(dst, src, len);
	return (dst);
}
