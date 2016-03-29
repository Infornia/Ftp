/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 14:13:11 by mwilk             #+#    #+#             */
/*   Updated: 2015/10/26 14:09:21 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char	*argv[] = {"ls", "-al", NULL};

	execv("/bin/ls", argv);
	perror("execv");
	return (-1);
}
