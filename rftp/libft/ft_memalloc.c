/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:57:43 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/08 03:45:25 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	void		*prd;

	prd = malloc(sizeof(char) * size);
	if (prd)
	{
		ft_bzero(prd, size);
		return (prd);
	}
	else
		return (NULL);
}
