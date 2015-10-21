/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:35:37 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/21 21:37:54 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ls(int cs, char *buf)
{
	char			**t;
	DIR				*dir;
	struct dirent	*sd;

	t = ft_strsplit(buf, ' ');
	if (!ft_strncmp(t[0], "ls", 2) && !t[1])
	{
		dir = opendir(".");
		send(cs, "Ls Success\n", 12, MSG_OOB);
		while ((sd = readdir(dir)))
		{
			send(cs, sd->d_name, ft_strlen(sd->d_name) + 1, MSG_OOB);
			send(cs, "\n", 2, MSG_OOB);
		}
		closedir(dir);
	}
	else
		put_error(cs, NOT_FOUND);
	if (t)
		free(t);
}
