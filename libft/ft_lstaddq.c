/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 19:23:07 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/05 23:17:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddq(t_list **alst, t_list *new)
{
	t_list	*end;

	if (!alst)
	{
		*alst = new;
		return ;
	}
	end = ft_lstlast(*alst);
	end->next = new;
}
