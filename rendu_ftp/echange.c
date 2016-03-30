/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 20:59:48 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/30 04:46:57 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char	*ft_path(char *src)
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

void	ft_cput2(t_truck *b, off_t size, int sock)
{
	char		*buff;

	buff = NULL;
	(void)b;
	buff = (char *)malloc(sizeof(char) * size);
	b->i = read(b->fd, buff, size);
	ft_send(sock, 0, ft_itoa(size), ft_intlen(size));
	ft_send(sock, 0, buff, size);
	ft_recv(sock, &buff);
	printf("%s\n", buff);
	free(buff);
}

void	ft_cput(t_truck *b, int sock)
{
	char		*path;
	struct stat	s;

	path = ft_path(b->line);
	if ((b->fd = open(path, O_RDONLY)) == -1)
	{
		printf("ERROR mauvais nom de ficher\n");
		ft_send(sock, 0, "nop", 3);
		return ;
	}
	else if ((b->i = fstat(b->fd, &s)) == -1)
	{
		printf("ERROR %s n'est pas un ficher\n", path);
		ft_send(sock, 0, "nop", 3);
		return ;
	}
	else if ((s.st_mode & S_IFMT) == S_IFREG)
	{
		ft_send(sock, 0, "ok", 2);
		ft_cput2(b, s.st_size, sock);
	}
	close(b->fd);
	free(path);
	return ;
}

void	ft_2get(t_truck *uni, char *path, int sock)
{
	int		len;
	char	*buff;

	len = 0;
	buff = NULL;
	if ((uni->fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		return ;
	ft_recv(sock, &uni->buff);
	len = ft_atoi(uni->buff);
	ft_recv(sock, &buff);
	write(uni->fd, buff, len);
	close(uni->fd);
	printf("SUCCESS\n");
	free(buff);
}

void	ft_get(t_truck *uni, int sock)
{
	char	*path;
	int		i;

	i = 3;
	path = ft_strdup(uni->line);
	while (path[i] == ' ')
		i++;
	ft_bzero(path, ft_strlen(path));
	path = ft_strncpy(path, &uni->line[i], ft_strlen(uni->line));
	path = ft_strtrim(path);
	ft_strdel(&uni->buff);
	uni->i = ft_recv(sock, &uni->buff);
	if ((i = ft_strcmp(uni->buff, "nop")) == 0)
	{
		ft_strdel(&uni->buff);
		uni->i = ft_recv(sock, &uni->buff);
		printf("%s\n", uni->buff);
		return ;
	}
	else if ((i = ft_strcmp(uni->buff, "ok")) == 0)
		ft_2get(uni, path, sock);
	free(path);
}
