/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:41:19 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/10 19:10:03 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (i < ft_strlen(s))
		{
			f(i, &s[i]);
			i++;
		}
	}
}
