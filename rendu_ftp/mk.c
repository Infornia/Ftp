/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:01:47 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/30 04:56:48 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void		ft_mkdir(t_data *uni)
{
	char	*str;

	uni->i = 5;
	if (ft_strlen(uni->buf) < 5)
	{
		ft_send(uni->cs, 0, "ERROR need a name\n", 18);
		return ;
	}
	else
	{
		str = ft_strdup(uni->buf);
		while (uni->i >= 0)
		{
			str[uni->i] = ' ';
			uni->i--;
		}
		if ((str = ft_strtrim(str)) == NULL)
		{
			ft_send(uni->cs, 0, "ERROR need a name\n", 18);
			return ;
		}
		mkdir(str, 0777);
		ft_send(uni->cs, 0, "SUCCESS\n", 8);
	}
}

void		gest_err(int sock)
{
	if (errno == EACCES)
	{
		ft_send(sock, 0, "ERROR Impossible de lire ou de parcourir un \
			composant du chemin d'acces\n", 78);
	}
	else if (errno == ERANGE)
		ft_send(sock, 0, "ERROR buffer trop petit\n", 24);
}

void		err_get(t_data *uni)
{
	ft_send(uni->cs, 0, "nop", 3);
	ft_send(uni->cs, 0, "ERROR le document demander \
		n\'est pas un fichier\n", 48);
	return ;
}

int			check_arg(t_data *uni, int m)
{
	int		i;

	i = 2;
	if (ft_strlen(uni->buf) > 3)
	{
		while (uni->buf[i] == ' ')
			i++;
		if (uni->buf[i] == '-' && uni->buf[i + 1] == 'a')
			m = 1;
		else
		{
			ft_send(uni->cs, 0, "ERROR use -a or nothing\n", 24);
			m = 2;
		}
	}
	else
		m = 0;
	return (m);
}
