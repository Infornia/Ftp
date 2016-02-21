/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:29:22 by ccholin           #+#    #+#             */
/*   Updated: 2015/03/20 19:59:41 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_malloc(char **str, int word, int len)
{
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (word + 1));
	while (i < word)
	{
		str[i] = (char *)malloc(sizeof(char) * (len + 1));
		i++;
	}
	if (str)
	{
		str[i] = NULL;
		return (str);
	}
	else
		return (NULL);
}

static int		ft_cword(char *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static int		ft_leng(char *s, char c)
{
	int		len;
	int		i;
	int		swap;

	i = 0;
	len = 0;
	swap = 0;
	while (s[i])
	{
		if (s[i] != c)
			swap++;
		if (s[i] != c && s[i + 1] == c)
		{
			if (swap > len)
				len = swap;
		}
		i++;
	}
	return (len);
}

static char		**ft_allow(char *s, char **str, char c)
{
	int		v;
	int		i;
	int		j;

	v = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] != c)
		{
			str[v][j] = s[i];
			j++;
		}
		else if ((s[i] != c && s[i + 1] == c) ||
				(s[i] != c && s[i + 1] == '\0'))
		{
			str[v][j] = s[i];
			str[v][j + 1] = '\0';
			j = 0;
			v++;
		}
		i++;
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		len;
	int		word;
	char	**str;

	str = NULL;
	if (!s)
		return (NULL);
	word = ft_cword((char *)s, c);
	len = ft_leng((char *)s, c);
	str = ft_malloc(str, word, len);
	if (!str)
		return (NULL);
	str = ft_allow((char *)s, str, c);
	return (str);
}
