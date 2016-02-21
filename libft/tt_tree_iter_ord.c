/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_tree_iter_ord.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 20:04:01 by mwilk             #+#    #+#             */
/*   Updated: 2015/03/25 18:05:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	tt_tree_iter_ord(t_tree *head, void (*f)(t_tree *node))
{
	if (!head)
		return ;
	tt_tree_iter_ord(head->left, f);
	(*f)(head);
	tt_tree_iter_ord(head->right, f);
}
