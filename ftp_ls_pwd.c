/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:35:37 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/22 15:25:52 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ls(int cs, char *buf)
{
	int				pid;
	int				status;
	char			**t;

	pid = fork();
	if (pid > 0)
	{
		dup2(cs, 1);
		dup2(cs, 2);
		close(cs);
		t = ft_strsplit(buf, ' ');
		if (!ft_strncmp(t[0], "ls", 2))
		{
			send(cs, "Ls Success\n", 12, MSG_OOB);
			execv("/bin/ls", &t[0]);
			ft_puts("Fail of execv Bro");
		}
		else
			put_error(cs, NOT_FOUND);
		if (t)
			free(t);
		exit(0);
	}
	else if (pid == 0)
		wait(&status);
	else
		exit(0);
}

void	pwd(int cs, char *buf)
{
	char	**t;
	size_t	cmp;
	char	buff[2048];
	char	*cwd;

	t = ft_strsplit(buf, ' ');
	cmp = ft_strncmp(t[0], "pwd", 3);
	if (cmp || (!cmp && t[1]))
	{
		put_error(cs, NOT_FOUND);
		return ;
	}
	send(cs, "Pwd Success\n", 13, MSG_OOB);
	cwd = getcwd(buff, 2048);
	send(cs, cwd, ft_strlen(cwd) + 1, MSG_OOB);
	send(cs, "\n", 2, MSG_OOB);
}
