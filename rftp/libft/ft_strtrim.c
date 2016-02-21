/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:47:00 by ccholin           #+#    #+#             */
/*   Updated: 2014/11/11 02:22:32 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_verif(char c)
{
	if ('\n' == c || '\t' == c || ' ' == c)
		return (1);
	return (0);
}

static int		ft_deb(char *s)
{
	int		i;

	i = 0;
	while (ft_verif(s[i]) && s[i] != '\0')
		i++;
	return (i);
}

static int		ft_end(char *s)
{
	int		i;

	i = ft_strlen(s);
	if (i > 0)
		i--;
	while (ft_verif(s[i]) && i >= 0)
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		deb;
	int		end;
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	deb = ft_deb((char *)s);
	end = ft_end((char *)s);
	if (deb > end)
		return (NULL);
	str = ft_strnew((end - deb) + 1);
	if (!str)
		return (NULL);
	if (end == 0)
		return (str);
	i = 0;
	while (deb <= end)
		str[i++] = s[deb++];
	return (str);
}
