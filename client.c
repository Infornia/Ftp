/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 13:52:18 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/04 13:30:16 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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

static int		transmission(int sock, char *line, char **buff)
{
	int		m;

	m = 1;
	if ((ft_strnstr(line, "pwd", 3)))
		tt_recv(sock, buff);
	else
		m = 0;
	return (m);
}

static void		recep(int sock, char *buff, char *line)
{
	int		r;
	int		t;

	while ((r = read(0, line, 2048)) > 0)
	{
		line[r] = 0;
		tt_send(sock, line, ft_strlen(line), 0);
		if (ft_strnstr(line, "quit", 4))
			break ;
		t = transmission(sock, line, &buff);
		if (!t)
		{
			tt_recv(sock, &buff);
			ft_puts(buff);
		}
		ft_strdel(&buff);
		ft_bzero(line, 2048);
		ft_putstr("\033[33m (>^.^)> Client <(^.^<) -> \033[0m");
	}
}

int			main(int ac, char **av)
{
	int		port;
	int		sock;
	char	*buff;
	char	*line;

	if (ac != 3)
	{
		printf("Usage: %s <addr> <port>\n", av[0]);
		exit(-1);
	}
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	buff = NULL;
	line = (char *)malloc(sizeof(char) * 2048);
	ft_bzero(buff, ft_strlen(buff));
	ft_putstr("\033[33m (>^.^)> Client <(^.^<) -> \033[0m");
	recep(sock, buff, line);
	printf("\033[32mGood bye !\n\033[0m");
	close(sock);
	free(line);
	return (0);
}
