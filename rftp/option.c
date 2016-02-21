/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccholin <ccholin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/15 18:15:55 by ccholin           #+#    #+#             */
/*   Updated: 2015/06/01 22:00:34 by ccholin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void					get_pwd(int sock)
{
	char				*buff;

	errno = 0;
	if ((buff = (char*)malloc(sizeof(char) * 2000)) == NULL)
	{
		send(sock, "erreur de malloc\n", 17, 0);
		return ;
	}
	if ((buff = getcwd(buff, 1023)) != NULL)
	{
		ft_send(sock, 0, buff, ft_strlen(buff));
		ft_send(sock, 0, "SUCCESS\n", 8);
	}
	else
		gest_err(sock);
}

void					test_dir(t_bail *uni, char *pwd)
{
	char				*where;
	int					m;

	m = 0;
	where = (char *)malloc(sizeof(char) * 2000);
	where = getcwd(where, 2000);
	if (ft_strlen(where) < ft_strlen(uni->pwd))
	{
		m = 1;
		chdir(pwd);
		ft_send(uni->cs, 0, "ERROR access denied\n", 20);
	}
	else
	{
		m = 0;
		ft_send(uni->cs, 0, "SUCCESS\n", 8);
	}
	free(where);
	return ;
}

void					ft_cd(t_bail *uni)
{
	char				*str;
	int					m;
	char				*pwd;

	pwd = (char *)malloc(sizeof(char) * 2000);
	m = 0;
	uni->i = 2;
	pwd = getcwd(pwd, 2000);
	str = ft_strdup(uni->buf);
	while (uni->i >= 0)
	{
		str[uni->i] = ' ';
		uni->i--;
	}
	str = ft_strtrim(str);
	if ((uni->i = chdir(str)) == -1)
	{
		ft_send(uni->cs, 0, "ERROR wrong path\n", 17);
		free(str);
		free(pwd);
		return ;
	}
	test_dir(uni, pwd);
	free(str);
	free(pwd);
}

char					*make_ls(int cond, DIR *flux)
{
	struct dirent		*dir;
	int					i;
	char				*rep;

	i = 0;
	while ((dir = readdir(flux)) != 0)
	{
		if (i == 0)
		{
			if (cond == 0 && dir->d_name[0] == '.')
				continue ;
			rep = ft_strdup(dir->d_name);
			rep = ft_strjoin(rep, "\n");
			i++;
		}
		else
		{
			if (cond == 0 && dir->d_name[0] == '.')
				continue ;
			rep = ft_strjoin(rep, dir->d_name);
			rep = ft_strjoin(rep, "\n");
		}
	}
	rep = ft_strjoin(rep, "SUCCES\n");
	return (rep);
}

void					ft_ls(t_bail *uni, int m)
{
	char				*rep;
	DIR					*flux;

	if ((m = check_arg(uni, 0)) == 2)
		return ;
	if ((flux = opendir("./")) == NULL)
	{
		ft_send(uni->cs, 0, "ERROR opendir fail\n", 19);
		return ;
	}
	rep = make_ls(m, flux);
	closedir(flux);
	ft_send(uni->cs, 0, rep, ft_strlen(rep));
	ft_strdel(&rep);
	return ;
}
