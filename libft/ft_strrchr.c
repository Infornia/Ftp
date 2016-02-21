/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 16:42:17 by mwilk             #+#    #+#             */
/*   Updated: 2014/11/12 20:38:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (str == NULL)
		return (NULL);
	if (c == '\0')
	{
		return ((char *)(str + i));
		i--;
	}
	while (i >= 0)
	{
		if (str[i] == ((char)c))
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
