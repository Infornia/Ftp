/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 12:15:27 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/26 18:37:11 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	get_file(int cs, char *file)
{
	int		fd;
	char	buf[1024];
	int		r;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		send(cs, "\033[31mFile doesn't exist my love\033[0m\n", 37, MSG_OOB);
		close(fd);
		return ;
	}
	send(cs, "\033[32mOk your file exist, i'm reading it\n\033[0m", 45, MSG_OOB);
	send(cs, GET, 2, MSG_OOB);
	while ((r = read(fd, buf, 1023)) > 0)
	{
		buf[r] = 0;
		send(cs, buf, r + 1, MSG_OOB);
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
