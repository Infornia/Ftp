/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 20:27:04 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/10 21:37:08 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (s != NULL && f != NULL)
	{
		dest = (char *)malloc(sizeof(char) * ft_strlen((char*)s));
		i = 0;
		while (s[i] != '\0')
		{
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
