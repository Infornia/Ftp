/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ls_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 20:35:37 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/26 13:25:01 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ls(int cs, char *buf)
{
	int				pid;
	int				status;
	char			**t;

	pid = fork();
	if (pid == 0)
	{
		write(cs, "\033[32mSUCCESS: Ls\n\033[0m", 25);
		dup2(cs, 1);
		dup2(cs, 2);
		t = ft_strsplit(buf, ' ');
		if (!ft_strncmp(t[0], "ls", 2))
		{
			execv("/bin/ls", &t[0]);
			ft_puts("Fail of execv Bro");
		}
		else
			put_error(cs, NOT_FOUND);
		if (t)
			free(t);
	}
	else if (pid > 0)
		wait(&status);
	else
		exit(0);
}

void	pwd(int cs, char *buf, char *home)
{
	char	**t;
	size_t	cmp;
	char	buff[2048];
	char	*cwd;
	int		move;

	move = ft_strlen(home);
	t = ft_strsplit(buf, ' ');
	cmp = ft_strncmp(t[0], "pwd", 3);
	if (cmp || (!cmp && t[1]))
	{
		put_error(cs, NOT_FOUND);
		return ;
	}
	send(cs, "\033[32mSUCCESS: Pwd\n\033[0m", 26, MSG_OOB);
	cwd = getcwd(buff, 2048) + move - 4;
	send(cs, cwd, ft_strlen(cwd) + 1, MSG_OOB);
	send(cs, "\n", 2, MSG_OOB);
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
	if (ft_strcmp(home, cwd) < 0)
		send(cs, "\033[32mSUCCESS: Cd\nChange directory\n\033[0m", 43, MSG_OOB);
	else
	{
		send(cs, "\033[32mSUCCESS: Cd\n\033[0m", 25, MSG_OOB);
		send(cs, "\033[31mHaha no you can't leave your home\n
				(Back to home) \n\033[0m", 63, MSG_OOB);
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
		send(cs, "\033[32mSUCCESS: Cd\n
				Back to Home my Friend !\n\033[0m", 51, MSG_OOB);
	}
	else if (!cmp && t[1])
		cd_helper(cs, home, t[1]);
	if (t)
		free(t);
}
