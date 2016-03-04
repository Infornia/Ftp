/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_tree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 16:37:09 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/22 20:21:04 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tt_tree_del(t_tree **parent, void (*del)(void *, size_t))
{
	t_tree	*tmp;

	tmp = *parent;
	if (tmp)
	{
		tt_tree_del(&tmp->left, del);
		tt_tree_del(&tmp->right, del);
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		*parent = NULL;
	}
}
