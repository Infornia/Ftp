/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:17:55 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/10 22:12:33 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_veri(char c)
{
	char	*ver;
	int		i;

	i = 0;
	ver = "\n\v\t\r\f ";
	while (ver[i] != '\0')
	{
		if (ver[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int				ft_atoi(char *str)
{
	int		i;
	int		res;
	int		neg;

	i = 0;
	neg = 1;
	res = 0;
	while (ft_veri(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}
