/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_tree_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:16:17 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 18:04:34 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*tt_tree_new(void const *content, size_t content_size)
{
	t_tree	*node;

	if (!(node = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	if (content)
	{
		if (!(node->content = (void *)malloc(content_size)))
			return (NULL);
		node->content = ft_memmove(node->content, content, content_size);
	}
	else
		node->content = NULL;
	node->content_size = !content ? 0 : content_size;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
