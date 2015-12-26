/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:52:48 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/26 17:57:33 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	put_error(int cs, int error_type)
{
	if (error_type == NOT_FOUND)
		send(cs, "\033[31mNot found\n\033[0m", 20, MSG_OOB);
}

void	quit(int cs, int ss)
{
	(void)ss;
	send(cs, "\033[32mSUCCESS: Quit\033[0m\n", 24, MSG_OOB);
}
