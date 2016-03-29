/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 13:44:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/29 21:46:12 by mwilk            ###   ########.fr       */
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
		ft_putstr("\033[31mError: Failed to Connect\033[0m\n");
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
		ft_putstr("\033[33m (>^.^)> Client <(^.^<) -> \033[0m");
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
	{
		printf("Usage: %s <addr> <port>\n", av[0]);
		exit(-1);
	}
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	b.buff = NULL;
	b.line = (char*)malloc(sizeof(char) * 2048);
	ft_putstr("\033[33m (>^.^)> Client <(^.^<) -> \033[0m");
	do_it(&b, sock);
	close(sock);
	free(b.line);
	printf("\033[32mGood bye !\n\033[0m");
	return (0);
}
