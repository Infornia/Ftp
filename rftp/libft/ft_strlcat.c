/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:49:59 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/12 01:34:48 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		deslen;
	size_t		srclen;
	size_t		i;
	size_t		j;

	j = 0;
	deslen = ft_strlen(dst);
	srclen = ft_strlen((char*)src);
	if (size <= deslen)
		return (size + srclen);
	i = deslen;
	while (size - 1 > i)
	{
		dst[i] = ((char *)src)[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (deslen + srclen);
}
