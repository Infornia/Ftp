/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkone <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:23:01 by dkone             #+#    #+#             */
/*   Updated: 2015/06/01 15:23:46 by dkone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static void			ft_send_size(int sock, size_t size)
{
	unsigned char	data[4];

	data[0] = (size >> (3 * 8)) & 0xFF;
	data[1] = (size >> (2 * 8)) & 0xFF;
	data[2] = (size >> (1 * 8)) & 0xFF;
	data[3] = (size >> (0 * 8)) & 0xFF;
	if ((send(sock, data, sizeof(data), 0)) < 0)
		printf("Echec de transmission");
}

static int			ft_acquittement(int sock)
{
	unsigned char	data[1];
	int				n;

	n = recv(sock, data, sizeof(data), 0);
	if (n == sizeof(data) && data[0] == 4)
		return (1);
	return (0);
}

static	void		ft_send_data(int sock, int fd, char *str, size_t size)
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
				r += send(sock, str + r, SIZE_BLOCK, 0);
			else
				r += send(sock, str + r, size - r, 0);
	}
}

void				ft_send(int sock, int fd, char *str, size_t size)
{
	ft_send_size(sock, size);
	if (ft_acquittement(sock))
	{
		ft_send_data(sock, fd, str, size);
		if (ft_acquittement(sock))
			return ;
		else
			printf("Echec de la transmission");
	}
	else
		printf("Echec de la transmission");
}
