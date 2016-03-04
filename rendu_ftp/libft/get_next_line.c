/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:26:26 by mwilk             #+#    #+#             */
/*   Updated: 2015/02/04 19:30:32 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		freedom(char **to_red, char **line)
{
	*line = ft_strdup(*to_red);
	free(*to_red);
	*to_red = NULL;
}

static int		send_cut_keep(char **line, char **to_red, char *mother_cutter)
{
	*line = *to_red;
	*mother_cutter = '\0';
	*to_red = ft_strdup(mother_cutter + 1);
	return (1);
}

static	void	ft_strjoin_gnl(char **to_red, char *bull)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(*to_red, bull);
	free(*to_red);
	*to_red = tmp;
}

int				get_next_line(const int fd, char **line)
{
	char			bull[BUFF_SIZE + 1];
	static char		*to_red[1024];
	char			*mother_cutter;
	int				ret;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!to_red[fd])
	{
		if ((ret = read(fd, bull, BUFF_SIZE)) < 1)
			return (ret);
		bull[ret] = 0;
		to_red[fd] = ft_strdup(bull);
	}
	while (!ft_strchr(to_red[fd], '\n') && (ret = read(fd, bull, BUFF_SIZE)))
	{
		bull[ret] = 0;
		ft_strjoin_gnl(&to_red[fd], bull);
	}
	if ((mother_cutter = ft_strchr(to_red[fd], '\n')))
		return (send_cut_keep(line, &to_red[fd], mother_cutter));
	freedom(&to_red[fd], line);
	return (ft_strlen(*line));
}
