/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:15:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/30 20:34:21 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	get_file(int cs, char *file)
{
	int		fd;
	int		r;
	char	buff[1024];

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		send(cs, "\033[31mFile doesn't exist my love\033[0m\n", 37, MSG_OOB);
		close(fd);
		return ;
	}
	send(cs, "\033[32m\006SUCCESS: Get\n\033[0m", 24, MSG_OOB);
	send(cs, GET, 2, MSG_OOB);
	while ((r = read(fd, buff, 1023)) > 0)
	{
		buff[r] = 0;
		send(cs, buff,  r + 1, MSG_OOB);
	}
	send(cs, END_GET, 2, MSG_OOB);
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
