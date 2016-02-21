/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:35:26 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/12 01:47:34 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*swp;

	i = 0;
	swp = (unsigned char *)src;
	while (n > i)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if ((unsigned char)swp[i] == (unsigned char)c)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
