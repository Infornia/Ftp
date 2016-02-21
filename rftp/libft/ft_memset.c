/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:01:29 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 23:23:38 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*nb;

	nb = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		nb[i] = (unsigned char)c;
		i++;
	}
	return ((void*)nb);
}
