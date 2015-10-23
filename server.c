/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 13:52:18 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/23 16:09:51 by mwilk            ###   ########.fr       */
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
		ft_putstr("\033[31mError: Bind Problem, Try another port please\033[0m\n");
		exit(0);
	}
	listen(sock, 22);
	return (sock);
}

void	do_something(t_data *d, char **e)
{
	(void)e;
	while (22)
	{
		d->r = read(d->cs, d->buf, 1023);
		d->buf[d->r - 1] = '\0';
		if (!ft_strncmp(d->buf, "ls", 2))
			ls(d->cs, d->buf);
		else if (!ft_strcmp(d->buf, "pwd"))
			pwd(d->cs, d->buf);
		else if (!ft_strncmp(d->buf, "cd", 2))
			cd(d->cs, d->buf, d->home);
		else if (!ft_strncmp(d->buf, "get", 3))
			get(d->cs, d->buf);
		else if (!ft_strcmp(d->buf, "quit"))
			quit(d, d->cs);
		write(1, d->buf, d->r);
		write(1, "\n", 1);
	}
}

void	fork_this(t_data *d, char **e, int sock)
{
	int		pid;
	int		status;

	while (22)
	{
		if ((d->cs = accept(sock, (struct sockaddr*)&d->csin, &d->cslen)) >= 0)
		{
			pid = fork();
			if (pid > 0)
				do_something(d, e);
			else if (pid == 0)
				wait(&status);
			else
				exit(0);
		}
	}
}

int		main(int ac, char **av, char **e)
{
	t_data					d;
	int						port;
	char					b[2048];

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	d.sock = create_server(port);
	d.home = getcwd(b, 2048);
	fork_this(&d, e, d.sock);
	close(d.cs);
	close(d.sock);
	return (0);
}
