/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_send.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 01:41:26 by mwilk             #+#    #+#             */
/*   Updated: 2016/02/23 07:57:03 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		send_size(int sock, size_t size)
{
	unsigned char	data[4];

	data[0] = (size >> (3 * 8)) & 0xFF;
	data[1] = (size >> (2 * 8)) & 0xFF;
	data[2] = (size >> (1 * 8)) & 0xFF;
	data[3] = (size >> (0 * 8)) & 0xFF;
	if ((send(sock, data, sizeof(data), 0)) < 0)
		printf("Error: failed transmission (send)\n");
}

static int		acquittement(int sock)
{
	unsigned char	data[1];
	int				n;

	n = recv(sock, data, sizeof(data), 0);
	printf("RECV: le n:%i, le data:%c", n, data[0]);
	if (n == sizeof(data) && data[0] == 4)
		return (1);
	return (0);
}

static void		send_data(int sock, int fd, char *s, size_t size)
{
	size_t			r;
	char			buf[SIZE_BLOCK];

	r = 0;
	if (fd)
		while ((r = read(fd, buf, SIZE_BLOCK)) > 0)
			send(sock, buf, r, 0);
	else
	{
		while (r < size)
			if (r - size >= SIZE_BLOCK)
				r += send(sock, s + r, SIZE_BLOCK, 0);
			else
				r += send(sock, s + r, size - r, 0);
	}
}

void			tt_send(int sock, int fd, char *s, size_t size)
{
	send_size(sock, size);
	if (acquittement(sock))
	{
		send_data(sock, fd, s, size);
		if (acquittement(sock))
			return ;
		else
			printf("Error: failed 2nd transmission\n");
	}
	else
			printf("Error: failed 1st transmission\n");
}
