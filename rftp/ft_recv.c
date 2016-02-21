/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkone <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 15:21:40 by dkone             #+#    #+#             */
/*   Updated: 2015/06/01 15:22:41 by dkone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

static	size_t		ft_recv_size(int sock)
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
		return (size);
	}
	return (size);
}

static	void		ft_send_acquittement(int sock)
{
	unsigned char	data[1];

	data[0] = 4;
	if ((send(sock, data, sizeof(data), 0)) < 0)
		printf("Echec de transmission\n");
}

static	void		ft_recv_data(int sock, size_t size, char **str)
{
	size_t				r;

	r = 0;
	*str = ft_strnew(size);
	while (r < size)
		r += recv(sock, *str + r, SIZE_BLOCK, 0);
}

size_t				ft_recv(int sock, char **str)
{
	size_t		size;

	size = ft_recv_size(sock);
	ft_send_acquittement(sock);
	ft_recv_data(sock, size, str);
	ft_send_acquittement(sock);
	return (size);
}
