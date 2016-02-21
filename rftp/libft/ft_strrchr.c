/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:51:00 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 23:46:49 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if ((int)s[i] == c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
