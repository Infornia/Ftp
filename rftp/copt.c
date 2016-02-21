/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 17:42:36 by ccholin           #+#    #+#             */
/*   Updated: 2015/06/02 21:21:42 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	ft_pwd(t_truck *b, int sock)
{
	ft_recv(sock, &b->buff);
	printf("%s\n", b->buff);
	ft_strdel(&b->buff);
	ft_recv(sock, &b->buff);
	printf("%s\n", b->buff);
}

int		c_trans(t_truck *b, int sock)
{
	int	m;

	m = 2;
	(void)b;
	(void)sock;
	if ((ft_strnstr(b->line, "put", 3)))
	{
		m = 1;
		ft_cput(b, sock);
	}
	else if ((ft_strnstr(b->line, "get", 3)))
	{
		m = 1;
		ft_get(b, sock);
	}
	else if ((ft_strnstr(b->line, "pwd", 3)))
	{
		m = 1;
		ft_pwd(b, sock);
	}
	else
		m = 0;
	return (m);
}
