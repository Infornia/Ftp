/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_recv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 00:21:36 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/21 02:01:57 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static	size_t		recv_size(int sock)
{
	unsigned char	data[4];
	size_t			size;

	size = 0;
	if ((recv(sock, data, sizeof(data), 0)) == sizeof(data))
	{
		size |= (data[0] << (3 * 8));
		size |= (data[1] << (2 * 8));
		size |= (data[2] << (1 * 8));
		size |= (data[3] << (0 * 8));
	}
	return (size);
}

static	void		tt_send_acquittement(int sock)
{
	unsigned char	data[1];

	data[0] = 4;
	if ((send(sock, data, sizeof(data), 0)) < 0)
		printf("Error: Failed transmission\n");
}

static	void		recv_data(int sock, size_t size, char **s)
{
	size_t		r;

	r = 0;
	*s = ft_strnew(size);
	while (r < size)
		r += recv(sock, *s + r, SIZE_BLOCK, 0);
}

size_t				tt_recv(int sock, char **s)
{
	size_t		size;

	size = recv_size(sock);
	tt_send_acquittement(sock);
	recv_data(sock, size, s);
	tt_send_acquittement(sock);
	return (size);
}
