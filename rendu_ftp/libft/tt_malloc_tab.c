/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt_malloc_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 18:06:45 by mwilk             #+#    #+#             */
/*   Updated: 2016/01/13 18:46:10 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tt_malloc_tab(int size_1, int size_2)
{
	char		**ret;
	int			i;

	ret = (char **)malloc(sizeof(char *) * (size_1 + 1));
	i = -1;
	while (++i < size_1)
		ret[i] = ft_strnew(size_2);
	return (ret);
}
