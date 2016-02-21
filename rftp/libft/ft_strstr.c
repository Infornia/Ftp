/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:23:39 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/06 01:46:21 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *meule, const char *aiguille)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (aiguille[i] == '\0')
		return ((char *)meule);
	len = ft_strlen((char *)aiguille);
	while (meule[i])
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
