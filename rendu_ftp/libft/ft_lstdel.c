/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:03:03 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/02 18:19:15 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*next;

	if (!del || !alst || !(*alst))
		return ;
	node = *alst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(&node, del);
		node = next;
	}
	*alst = NULL;
}
