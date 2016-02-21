/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 21:07:32 by ccholin           #+#    #+#             */
/*   Updated: 2015/06/01 19:18:42 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void					usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr("<addr> <port>\n");
	exit(-1);
}

int						create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	if (ft_strnstr(addr, "Localhost", 9) != NULL)
		sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	else
		sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Connect error\n");
		exit(2);
	}
	return (sock);
}

void					do_it(t_truck *b, int sock)
{
	while ((b->i = read(0, b->line, 2048)) > 0)
	{
		b->line[b->i] = '\0';
		ft_send(sock, 0, b->line, ft_strlen(b->line));
		if ((ft_strnstr(b->line, "quit", 4)) != NULL)
			break ;
		b->r = c_trans(b, sock);
		if (b->r == 0)
		{
			ft_recv(sock, &b->buff);
			printf("%s\n", b->buff);
		}
		ft_strdel(&b->buff);
		ft_bzero(b->line, 2048);
		write(1, "client$$$:", 10);
	}
	return ;
}

int						main(int ac, char **av)
{
	int					port;
	int					sock;
	t_truck				b;

	b.i = 0;
	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	b.buff = NULL;
	b.line = (char*)malloc(sizeof(char) * 2048);
	ft_bzero(b.buff, ft_strlen(b.buff));
	write(1, "client$$$:", 10);
	do_it(&b, sock);
	close(sock);
	free(b.line);
	return (0);
}
