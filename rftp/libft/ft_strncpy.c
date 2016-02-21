/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:18:09 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 00:36:28 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else if (src[i] == '\0')
		{
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
		}
	}
	return (dst);
}
