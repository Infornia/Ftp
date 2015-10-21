/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 13:52:18 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/21 21:47:56 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	usage(char *s)
{
	ft_putstr("Usage: ");
	ft_putstr(s);
	puts(" <port>");
	exit(-1);
}

int		create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("\033[31mError: Bind Problem, Try another port please\033[0m\n");
		exit(0);
	}
	listen(sock, 22);
	return (sock);
}

void	do_something(t_data *d, char **e)
{
	(void)e;
	char *s;

	s = "\033[32mBye My Friend, you're disconnected\033[0m\n";
	while (22)
	{
		d->r = read(d->cs, d->buf, 1023);
		d->buf[d->r] = '\0';
		write(1, d->buf, d->r);
		write(1, "\n", 1);
		if (!ft_strncmp(d->buf, "ls", 2))
			ls(d->cs, d->buf);
		else if (!ft_strncmp(d->buf, "quit", 4))
		{
			send(d->cs, s, ft_strlen(s) + 1, MSG_OOB);
			send(d->cs, "\006", 2, MSG_OOB);
		}
		send(d->cs, "\007", 2, 0);
	}
}

void	fork_this(t_data *d, char **e, int sock)
{
	d->cs = accept(sock, (struct sockaddr*)&d->csin, &d->cslen);
	if (fork() == 0)
		do_something(d, e);
	else
		fork_this(d, e, sock);
}

int		main(int ac, char **av, char **e)
{
	t_data					d;
	int						port;
	int						sock;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	fork_this(&d, e, sock);
	close(d.cs);
	close(sock);
	return (0);
}