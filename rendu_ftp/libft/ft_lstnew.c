/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:12:19 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/06 17:20:45 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*to_ret;

	if (!(to_ret = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		to_ret->content_size = 0;
		to_ret->content = NULL;
	}
	else
	{
		if (!(to_ret->content = malloc(content_size)))
			return (NULL);
		to_ret->content = ft_memcpy(to_ret->content, content, content_size);
		to_ret->content_size = content_size;
	}
	to_ret->next = NULL;
	return (to_ret);
}
