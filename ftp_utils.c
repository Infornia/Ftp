/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:52:48 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/24 15:53:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	put_error(int cs, int error_type)
{
	if (error_type == NOT_FOUND)
		send(cs, "Not found\n", 12, MSG_OOB);
}

void	quit(int cs, int ss)
{
	send(cs, "\033[32mSUCCESS\033[0m\n", 19, MSG_OOB);
	close(ss);
	exit(0);
}
