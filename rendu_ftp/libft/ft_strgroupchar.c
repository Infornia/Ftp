/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strgroupchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:25:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 17:52:21 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strgroupchar(const char *s, char c)
{
	char		*ret;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	ret = ft_strnew(ft_strlen(s) + 1);
	i = 0;
	j = 0;
	while (s[i])
	{
		ret[j] = s[i];
		if (s[i] == c && s[i + 1] == c)
			i++;
		i++;
		j++;
	}
	return (ret);
}
