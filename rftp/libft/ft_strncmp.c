/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 01:30:49 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 22:34:59 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((!s1 && !s2) || n == 0)
		return (0);
	if (s1 == NULL)
		return (-1);
	if (s2 == NULL)
		return (1);
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		else if (s1[i] == 0 && s2[i] != s1[i])
			return (-1);
		else if (s2[i] == 0 && s1[i] != s2[i])
			return (1);
		else if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] == '\0' && s2[i] != '\0'))
		return (s1[i] - s2[i]);
	return (0);
}
