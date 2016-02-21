/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:34:19 by ccholin           #+#    #+#             */
/*   Updated: 2015/02/16 22:35:33 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;

	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2));
	s3 = ft_memalloc(len + 1);
	if (!s3)
		return (NULL);
	if (s1 != NULL && s2 != NULL)
	{
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}
