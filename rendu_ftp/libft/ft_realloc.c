/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:42:11 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/01 23:26:52 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*to_ret;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		to_ret = (void *)ft_memalloc(sizeof(char));
	else
		to_ret = (void *)ft_memalloc(size);
	if (to_ret == NULL)
		return (NULL);
	ft_bzero(to_ret, (size) ? size : sizeof(char));
	if (old > size)
		ft_memcpy(to_ret, ptr, (size) ? size : sizeof(char));
	else
		ft_memcpy(to_ret, ptr, old);
	ft_memdel((void *)&ptr);
	return (to_ret);
}
