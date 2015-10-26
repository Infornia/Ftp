/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:16:54 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/26 13:19:05 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
**includes
*/

# include <fcntl.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include "Libft/includes/libft.h"

/*
**defines
*/

# define NOT_FOUND 1
# define END "\005"

typedef struct	s_data
{
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int					r;
	char				buf[1024];
	char				*home;

	int					run;
}				t_data;

/*
**ftp_ls_pwd.c
*/

void			ls(int cs, char *buf);
void			pwd(int cs, char *buf);
void			cd(int cs, char *buf, char *home);

/*
**ftp_utils.c
*/

void			put_error(int cs, int error_type);
void			quit(t_data *d, int cs);

/*
**ftp_get.c
*/

void			get(int cs, char *buf);

#endif
