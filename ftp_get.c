/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:15:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/28 18:49:11 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char		*prepare_dl(char *file)
{
	char	*line;

	line = malloc(sizeof(char) * 1025)
	ft_bzero(&line);
	line = ft_strcat(line, "get ");
	line = ft_strcat(line, file);
	line = ft_strcat(line, " ");
	return (line);
}

static void	get_file(int cs, char *file)
{
	int		fd;
	char	*to_send;
	char	*tmp;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		send(cs, "\033[31mFile doesn't exist my love\033[0m\n", 37, MSG_OOB);
		close(fd);
		return ;
	}
	send(cs, "\033[32mOk your file exist, i'm reading it\n\033[0m", 45, MSG_OOB);
	to_send = prepare_dl(file);
	while (get_next_line(fd, &tmp) > 0)
		to_send = ft_strjoin(to_send, tmp);
	send(cs, to_send, ft_strlen(to_send) + 1, MSG_OOB);
	free(to_send);
	close(fd);
}

void		get(int cs, char *buf)
{
	char	**t;
	size_t	cmp;

	t = ft_strsplit(buf, ' ');
	cmp = ft_strcmp(t[0], "get");
	if (cmp || (!cmp && !t[1]))
	{
		put_error(cs, NOT_FOUND);
		free(t);
		return ;
	}
	else
		get_file(cs, t[1]);
	if (t)
		free(t);
}
