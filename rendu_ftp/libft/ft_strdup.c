/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:09:16 by mwilk             #+#    #+#             */
/*   Updated: 2014/11/08 18:20:43 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char*)malloc(sizeof(char*) * (ft_strlen(s1) + 1));
	if (s1 == NULL || dup == NULL)
		return (NULL);
	return (ft_strcpy(dup, s1));
}
