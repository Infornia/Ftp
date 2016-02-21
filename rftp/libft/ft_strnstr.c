/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:54:35 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 23:48:56 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *meule, const char *aiguille, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		len;

	j = 0;
	i = 0;
	if (aiguille[i] == '\0')
		return ((char *)meule);
	len = ft_strlen((char *)aiguille);
	while (i < n)
	{
		if (meule[i] == aiguille[j])
		{
			i++;
			j++;
			if (aiguille[j] == '\0')
				return ((char *)meule + (i - len));
		}
		else if (meule[i] != aiguille[j])
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
