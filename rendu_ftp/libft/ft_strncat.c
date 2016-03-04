/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:51:33 by mwilk             #+#    #+#             */
/*   Updated: 2014/11/08 17:56:53 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(dst);
	j = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	if (src[j] && j <= n)
		while (src[j] && j < n)
		{
			dst[i + j] = src[j];
			j++;
		}
	dst[i + j] = '\0';
	return (dst);
}
