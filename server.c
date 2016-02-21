/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 13:52:18 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/21 02:19:02 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	usage(char *s)
{
	printf("Usage: %s <port>", s);
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
		ft_putstr("\033[31mError: Bind Problem,Try another port please\033[0m\n");
		exit(0);
	}
	listen(sock, 22);
	return (sock);
}

void	do_something(t_data *d, char **e)
{
	(void)e;
	if (ft_strnstr(d->buf, "ls", 2))
		ls(d->cs, d->buf);
	else if (ft_strnstr(d->buf, "pwd", 3))
		pwd(d->cs, d->buf, d->home);
	else if (ft_strnstr(d->buf, "cd", 2))
		cd(d->cs, d->buf, d->home);
	else if (ft_strnstr(d->buf, "get", 3))
		get(d->cs, d->buf);
	else if (ft_strnstr(d->buf, "quit", 4))
		quit(d->cs, d->sock);
	else
		put_error(d->cs, NOT_FOUND);
	ft_bzero(d->buf, ft_strlen(d->buf));
}

static t_data		*init(t_data *d, char *port)
{
	char					b[2048];

	d = (t_data *)malloc(sizeof(t_data));
	d->port = ft_atoi(port);
	d->sock = create_server(d->port);
	d->home = getcwd(b, 2048);
	return (d);
}

int		main(int ac, char **av, char **e)
{
	t_data					*d;
	pid_t					pid;

	if (ac != 2)
		usage(av[0]);
	d = NULL;
	d = init(d, av[1]);
	while (22)
	{
		d->cs = accept(d->sock, (struct sockaddr*)&d->csin, &d->cslen);
		if (!(pid = fork()))
		{
			ft_puts("Client connected");
			while ((d->ret = tt_recv(d->cs, &d->buf)) > 0)
			{
				do_something(d, e);
				ft_strdel(&d->buf);
			}
		}
	}
	close(d->sock);
	return (0);
}
