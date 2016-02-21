/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:25:00 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 22:12:14 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenn(int n)
{
	int		len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char		*ft_allow(char *str, int n)
{
	int		i;
	int		neg;

	neg = 0;
	i = 0;
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while ((n / 10) > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	str[i] = n + '0';
	if (neg == 1)
		str[++i] = '-';
	str[i + 1] = '\0';
	return (str);
}

static char		*ft_reverse(char *str)
{
	int		i;
	int		len;
	char	*swap;

	len = ft_strlen(str);
	swap = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	len--;
	while (len >= 0)
	{
		swap[i] = str[len];
		i++;
		len--;
	}
	swap[i] = '\0';
	ft_strcpy(str, swap);
	return (str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_lenn(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	str = ft_allow(str, n);
	str = ft_reverse(str);
	return (str);
}
