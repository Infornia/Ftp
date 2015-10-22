/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:16:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/22 18:20:39 by mwilk            ###   ########.fr       */
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
	char	*home;
}				t_data;

/*
**ftp_ls_pwd.c
*/

void	ls(int cs, char *buf);
void	pwd(int cs, char *buf);
void	cd(int cs, char *buf, char *home);

/*
**ftp_utils.c
*/

void	put_error(int cs, int error_type);
void	quit(int cs);

#endif
