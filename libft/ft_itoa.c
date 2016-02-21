/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 11:56:00 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/01 23:29:59 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_lengths(size_t *len, int *p_10, int n)
{
	*len = 0;
	if (n < 0)
	{
		*len = 1;
		n = -n;
	}
	*p_10 = 1;
	while (n / *p_10 > 9)
	{
		*p_10 *= 10;
		*len += 1;
	}
}

char		*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	int		p_10;
	size_t	i;

	i = 0;
	init_lengths(&len, &p_10, n);
	ret = (char *)malloc((sizeof(*ret) * (len + 1)));
	if (ret == NULL || n == -2147483648)
		return (ret = !ret ? ret : "-2147483648");
	if (n < 0)
	{
		ret[i++] = '-';
		n = -n;
	}
	while (p_10 > 0)
	{
		ret[i++] = (n / p_10 % 10) + '0';
		p_10 /= 10;
	}
	ret[i] = '\0';
	return (ret);
}
