/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 13:52:18 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/30 22:18:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		usage(char *s)
{
	printf("Usage: %s <addr> <port>\n", s);
	exit(-1);
}

static void	quit_client(int sock, char *buf)
{
	if (!ft_strcmp(buf, "quit"))
	{
		printf("\033[32mGood bye !\033[0m");
		close(sock);
		exit(0);
	}
}

static void	create_file(char *buff, int r, int sock)
{
	int		fd;
	char	*begin;

	begin = ft_strchr(buff, *GET) + 1;
	printf("The FIRST r into the create %i\n The stockage: %s\n", r, buff);
	if (begin && !(*begin))
	{
		printf("Char alone");
		r = recv(sock, buff, sizeof(buff) - 1, 0);
		write(fd, buff, r);
	}
	else if (begin && *begin)
	{
		write(fd, begin, r);
		printf("string to put: %s\n", begin);
	}
	if ((fd = open("Download/abc", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | O_TRUNC)) < 0)
	{
		ft_putendl("Failed to open");
		return ;
	}
	if (buff[0] == *GET && r > 2)
		write(fd, buff + 1, ft_strlen(buff) - 2);
	r = recv(sock, buff, sizeof(buff) - 1, 0);
	buff[r] = 0;
	printf("The SECOND r into the create %i\n The stockage: %s\n", r, buff);
	close(fd);
}


void		recep(int sock)
{
	int		r;
	char	buff[1024];

	while ((r = recv(sock, buff, sizeof(buff) - 1, 0)) > 0)
	{
		buff[r] = 0;
		if (ft_strequ(buff, END))
			return ;
		if (ft_strchr(buff, *GET))
		{
			create_file(buff, r, sock);
			return ;
		}
		printf("The r %i\n", r);
		write(1, buff, r);
	}
	if (r == -1)
	{
		printf("\033[31mERROR: Recep problem\n\033[0m");
		exit(2);
	}
}

int			create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("\033[31mError: Failed to Connect\033[0m\n");
		exit(0);
	}
	return (sock);
}

int			main(int ac, char **av)
{
	int		port;
	int		sock;
	int		r;
	char	buff[1024];

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	while (22)
	{
		ft_putstr("\033[33m (>^.^)> Client <(^.^<) -> \033[0m");
		r = read(0, buff, 1023);
		buff[r - 1] = 0;
		send(sock, buff, r + 1, MSG_OOB);
		recep(sock);
		quit_client(sock, buff);
	}
	close(sock);
	return (0);
}
