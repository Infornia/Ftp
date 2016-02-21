/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:11:05 by mwilk             #+#    #+#             */
/*   Updated: 2014/12/06 15:27:23 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_word(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static size_t	nb_word(const char *s, char c)
{
	size_t	i;
	size_t	nb;
	int		in;

	nb = 0;
	i = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] == c && in)
			in = !in;
		else if (s[i] != c && !in)
		{
			nb++;
			in = !in;
		}
		i++;
	}
	return (nb);
}

static char		**tab_alloc(size_t size)
{
	char	**ret;

	ret = (char **)malloc(sizeof(*ret) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[0] = NULL;
	return (ret);
}

static void		split(char **ret, const char *s, char c)
{
	size_t	j;
	size_t	size;
	char	*word;

	j = 0;
	while (*s)
	{
		size = size_word(s, c);
		if (size)
		{
			word = ft_strsub(s, 0, size);
			ret[j] = word;
			j++;
		}
		s += size;
		while (*s == c)
			++s;
	}
	ret[j] = NULL;
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ret;
	size_t	nb;

	if (!s)
		return (NULL);
	nb = nb_word(s, c);
	ret = tab_alloc(nb);
	if (ret == NULL)
		return (NULL);
	split(ret, s, c);
	return (ret);
}
