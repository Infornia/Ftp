/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchartrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:25:22 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 17:51:39 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchartrim(const char *s, char c)
{
	char			*ret;
	unsigned int	i;
	int				j;
	int				t_start;

	t_start = 0;
	i = 0;
	j = 0;
	ret = ft_strnew(ft_strlen(s) + 1);
	while (i < ft_strlen(s))
	{
		if (!t_start && s[i] == c)
			i++;
		else
		{
			t_start = 1;
			ret[j++] = s[i++];
		}
	}
	while (ret[--j] == c)
		ret[j] = '\0';
	return (ret);
}
