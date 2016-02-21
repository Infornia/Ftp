/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:26:30 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/12 00:16:44 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*swap;

	i = 0;
	swap = (unsigned char *)ft_strdup((char *)src);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)swap)[i];
		i++;
	}
	return (dest);
}
