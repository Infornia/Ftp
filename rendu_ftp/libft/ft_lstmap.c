/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:02:24 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/05 23:21:38 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*l_new;
	t_list		*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	while (lst)
	{
		ft_lstaddq(&tmp, f(lst));
		lst = lst->next;
	}
	l_new = tmp->next;
	return (l_new);
}
