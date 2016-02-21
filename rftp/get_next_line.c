/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 04:23:49 by ccholin           #+#    #+#             */
/*   Updated: 2015/02/11 00:49:33 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stock_line(char **line, char *stock)
{
	char	*tmp;
	int		size;

	tmp = stock;
	if ((tmp = ft_strchr(stock, '\n')))
	{
		*tmp = '\0';
		size = ft_strlen(stock);
		*tmp = '\n';
		*line = ft_strsub(stock, 0, size);
		return (stock + size);
	}
	*line = ft_strdup(stock);
	return (stock + ft_strlen(stock));
}

int		take_line(char **stock, char *buff, char **line)
{
	if ((*stock = ft_strchr(buff, '\n')))
	{
		*stock = ft_strsub(buff, (ft_strlen(buff)
					- ft_strlen(*stock)), ft_strlen(*stock)) + 1;
		if (*line)
			*line = ft_strjoin(*line, ft_strsub(buff, 0, ft_strlen(buff)
						- ft_strlen(*stock) - 1));
		else
			*line = ft_strdup(ft_strsub(buff, 0, ft_strlen(buff)
						- ft_strlen(*stock) - 1));
		return (1);
	}
	if (*line)
		*line = ft_strjoin(*line, buff);
	else
		*line = ft_strdup(buff);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char		*stock;
	int				ret;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (stock)
	{
		stock = stock_line(line, stock);
		if (*stock == '\n')
		{
			stock++;
			return (1);
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((take_line(&stock, buff, line)) == 1)
			return (1);
	}
	if (ret == 0)
		return (0);
	return (-1);
}
