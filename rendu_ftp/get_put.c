/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 04:39:53 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/30 04:56:47 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static void	ft_2put(t_data *uni, char *path, char *buff)
{
	int		len;

	len = 0;
	if ((uni->fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		return ;
	ft_recv(uni->cs, &uni->buf);
	len = ft_atoi(uni->buf);
	ft_strdel(&buff);
	ft_recv(uni->cs, &buff);
	write(uni->fd, buff, len);
	close(uni->fd);
	ft_send(uni->cs, 0, "SUCCESS\n", 8);
	free(buff);
}

void		ft_put(t_data *uni)
{
	char	*path;
	int		i;
	char	*buff;

	i = 3;
	buff = NULL;
	path = ft_strdup(uni->buf);
	while (path[i] == ' ')
		i++;
	ft_bzero(path, ft_strlen(path));
	path = ft_strncpy(path, &uni->buf[i], ft_strlen(uni->buf));
	path = ft_strtrim(path);
	ft_strdel(&uni->buf);
	ft_recv(uni->cs, &buff);
	if ((i = ft_strcmp(buff, "nop")) == 0)
		return ;
	else if ((i = ft_strcmp(buff, "ok")) == 0)
		ft_2put(uni, path, buff);
	free(path);
}

char		*ft_path(char *src)
{
	char		*path;
	int			i;

	i = 3;
	path = ft_strdup(src);
	while (path[i] == ' ')
		i++;
	ft_bzero(path, ft_strlen(path));
	path = ft_strncpy(path, &src[i], ft_strlen(src));
	path = ft_strtrim(path);
	return (path);
}

void		ft_sget2(t_data *b, off_t size)
{
	char		*buff;

	ft_send(b->cs, 0, ft_itoa(size), ft_intlen(size));
	buff = (char *)malloc(sizeof(char) * size);
	b->i = read(b->fd, buff, size);
	ft_send(b->cs, 0, buff, size);
	free(buff);
}

void		ft_sget(t_data *b)
{
	char		*path;
	struct stat	s;

	path = ft_path(b->buf);
	if ((b->fd = open(path, O_RDONLY)) == -1)
	{
		ft_send(b->cs, 0, "nop", 3);
		ft_send(b->cs, 0, "ERROR mauvais nom de ficher\n", 28);
	}
	else if ((b->i = fstat(b->fd, &s)) == -1)
	{
		ft_send(b->cs, 0, "nop", 3);
		ft_send(b->cs, 0, "ERROR not a file\n", 18);
	}
	else if ((s.st_mode & S_IFMT) == S_IFREG)
	{
		ft_send(b->cs, 0, "ok", 2);
		ft_sget2(b, s.st_size);
	}
	else
		err_get(b);
	if (b->fd != -1)
		close(b->fd);
	free(path);
	return ;
}
