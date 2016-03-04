/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:35:37 by mwilk             #+#    #+#             */
/*   Updated: 2016/03/04 12:43:06 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ls(int cs, char *buf)
{
	pid_t			pid;
	char			**t;

	ft_puts("reached ls");
	if (!(pid = fork()))
	{
		ft_puts("Inside ls");
		send(cs, "\033[32mSUCCESS: Ls\n\033[0m", 22, 0);
		ft_puts("ls after send");
		dup2(cs, 1);
		dup2(cs, 2);
		t = ft_strsplit(buf, ' ');
		if (!ft_strncmp(t[0], "ls", 2))
		{
			execv("/bin/ls", &t[0]);
			ft_putendl("Fail of execv Bro");
		}
		else
			put_error(cs, NOT_FOUND);
		if (t)
			free(t);
	}
}

void	pwd(int cs, char *buf)
{
	char	*buff;

	(void)buf;
	buff = malloc(2048);
	if ((buff = getcwd(buff, 2048)))
	{
		tt_send(cs, buff, ft_strlen(buff), 0);
		tt_send(cs, "\033[32mSUCCESS: Pwd\n\033[0m", 23, 0);
	}
	else
		tt_send(cs, "\033[31mERROR: Pwd\n\033[0m", 20, 0);
	free(buff);
}

void	cd_helper(int cs, char *home, char *folder)
{
	char		buff[2048];
	char		*cwd;

	cwd = getcwd(buff, 2048);
	if (!strncmp(home, cwd, ft_strlen(home)))
		chdir(folder);
	else
	{
		put_error(cs, NOT_FOUND);
		chdir(home);
	}
	cwd = getcwd(buff, 2048);
	if (ft_strcmp(home, cwd) < 0)
		send(cs, "\033[32mSUCCESS: Cd\nChange directory\n\033[0m", 39, 0);
	else
	{
		send(cs, "\033[32mSUCCESS: Cd\n\033[0m", 22, 0);
		send(cs, "\033[31mHaha no you can't leave your home\n(Back to home) \n\033[0m", 60, 0);
		chdir(home);
	}
}

void	cd(int cs, char *buf, char *home)
{
	char	**t;
	size_t	cmp;

	t = ft_strsplit(buf, ' ');
	cmp = ft_strcmp(t[0], "cd");
	if (cmp)
	{
		put_error(cs, NOT_FOUND);
		return ;
	}
	else if (!cmp && !t[1])
	{
		chdir(home);
		tt_send(cs, "\033[32mSUCCESS: Cd\nBack to Home my Friend !\n\033[0m", 47, 0);
	}
	else if (!cmp && t[1])
		cd_helper(cs, home, t[1]);
	if (t)
		free(t);
}
