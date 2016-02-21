/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/27 21:07:32 by ccholin           #+#    #+#             */
/*   Updated: 2015/06/01 20:13:12 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void					usage(char *str)
{
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr("<port>\n");
	exit(-1);
}

int						create_server(int port)
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
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putstr("Bind error\n");
		exit(2);
	}
	listen(sock, 42);
	return (sock);
}

int						translate(t_bail *uni)
{
	if (ft_strnstr(uni->buf, "pwd", 3) != NULL)
		get_pwd(uni->cs);
	else if (ft_strnstr(uni->buf, "quit ", 4) != NULL)
		close(uni->cs);
	else if (ft_strnstr(uni->buf, "cd ", 3) != NULL)
		ft_cd(uni);
	else if (ft_strnstr(uni->buf, "ls", 2) != NULL)
		ft_ls(uni, 0);
	else if (ft_strnstr(uni->buf, "put", 3) != NULL)
		ft_put(uni);
	else if (ft_strnstr(uni->buf, "get", 3) != NULL)
		ft_sget(uni);
	else if (ft_strnstr(uni->buf, "mkdir", 5) != NULL)
		ft_mkdir(uni);
	else
		ft_send(uni->cs, 0, "ERROR mauvaise commande\n", 24);
	ft_bzero(uni->buf, ft_strlen(uni->buf));
	return (1);
}

t_bail					*init_uni(t_bail *uni, char *str)
{
	uni = (t_bail*)malloc(sizeof(t_bail));
	uni->pwd = (char *)malloc(sizeof(char) * 2048);
	uni->pwd = getcwd(uni->pwd, 2048);
	uni->port = ft_atoi(str);
	uni->sock = create_server(uni->port);
	return (uni);
}

int						main(int ac, char **av)
{
	t_bail				*uni;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	pid_t				son;

	if (ac != 2)
		usage(av[0]);
	uni = NULL;
	uni = init_uni(uni, av[1]);
	uni->ret = 1;
	while (1)
	{
		uni->cs = accept(uni->sock, (struct sockaddr*)&csin, &cslen);
		if (!(son = fork()))
		{
			printf("Client connected\n");
			while ((uni->ret = ft_recv(uni->cs, &uni->buf)) > 0)
			{
				translate(uni);
				ft_strdel(&uni->buf);
			}
		}
	}
	close(uni->sock);
	return (0);
}
