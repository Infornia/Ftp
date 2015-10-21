/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:16:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/21 21:03:47 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

/*
**includes
*/

#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "libft.h"

/*
**defines
*/

#define NOT_FOUND 1

typedef struct s_data
{
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		csin;
	int		r;
	char	buf[1024];
}				t_data;

/*
**ftp_ls.c
*/

void	ls(int cs, char *buf);

/*
**ftp_utils.c
*/

void	put_error(int cs, int error_type);

#endif
