/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_tree_iter_rev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 20:04:01 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 18:04:51 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tt_tree_iter_rev(t_tree *head, void (*f)(t_tree *node))
{
	if (!head)
		return ;
	tt_tree_iter_rev(head->right, f);
	(*f)(head);
	tt_tree_iter_rev(head->left, f);
}
