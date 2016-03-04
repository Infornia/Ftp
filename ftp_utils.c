/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:52:48 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/04 12:43:52 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	put_error(int cs, int error_type)
{
	if (error_type == NOT_FOUND)
		tt_send(cs, "\033[31mNot found\n\033[0m", 20, 0);
}

void	quit(int cs, int ss)
{
	(void)ss;
	tt_send(cs, "\033[32mSUCCESS: Quit\033[0m\n", 24, 0);
}
