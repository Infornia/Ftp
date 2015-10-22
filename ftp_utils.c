/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:52:48 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/22 11:02:56 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	put_error(int cs, int error_type)
{
	if (error_type == NOT_FOUND)
		send(cs, "Not found\n", 10, MSG_OOB);
}

void	quit(int cs)
{
	char *s;

	s = "\033[32mBye My Friend, you're disconnected\033[0m\n";
	send(cs, s, ft_strlen(s) + 1, MSG_OOB);
	send(cs, "\006", 2, MSG_OOB);
}
