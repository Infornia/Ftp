/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 21:01:34 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/30 04:58:08 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include "libft.h"
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <errno.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>

# define SIZE_BLOCK 8

typedef struct			s_truck
{
	char				*line;
	int					i;
	int					r;
	int					len;
	char				*buff;
	int					fd;
}						t_truck;

typedef struct			s_data
{
	int					port;
	int					sock;
	int					cs;
	int					r;
	size_t				ret;
	int					i;
	char				*buf;
	char				*pwd;
	int					fd;
}						t_data;

int						get_next_line(int const fd, char **line);
void					get_pwd(int sock);
void					ft_cd(t_data *uni);
void					ft_ls(t_data *uni, int m);
void					ft_cput(t_truck *b, int sock);
void					ft_put(t_data *uni);
void					ft_get(t_truck *uni, int sock);
void					ft_sget(t_data *b);
void					gest_err(int sock);
void					ft_mkdir(t_data *uni);
int						check_arg(t_data *uni, int m);
int						c_trans(t_truck *b, int sock);
size_t					ft_recv(int sock, char **str);
void					ft_send(int sock, int fd, char *str, size_t size);
void					err_get(t_data *uni);
#endif
