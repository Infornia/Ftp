/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:39:10 by ccholin           #+#    #+#             */
/*   Updated: 2015/02/05 18:51:03 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(char *str)
{
	int		i;
	char	*des;
	int		len;

	len = ft_strlen(str) + 1;
	i = 0;
	if ((des = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	while (str[i])
	{
		des[i] = str[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}
