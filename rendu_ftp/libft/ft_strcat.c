/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:36:51 by mwilk             #+#    #+#             */
/*   Updated: 2014/11/10 15:08:51 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char		*dst;
	const char	*src;
	int			i;
	int			j;

	dst = (char *)s1;
	src = (const char *)s2;
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	if (!dst[i] && src[j])
		while (src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	dst[i] = '\0';
	return (dst);
}
