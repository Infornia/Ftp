/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 21:23:13 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/01 23:26:18 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_cp;
	const char	*src_cp;
	size_t		i;
	size_t		dlen;

	dst_cp = dst;
	src_cp = src;
	i = size;
	while (i-- != 0 && *dst_cp != '\0')
		++dst_cp;
	dlen = dst_cp - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src_cp));
	while (*src_cp != '\0')
	{
		if (i != 1)
		{
			*dst_cp++ = *src_cp;
			--i;
		}
		++src_cp;
	}
	*dst_cp = '\0';
	return (dlen + (src_cp - src));
}
