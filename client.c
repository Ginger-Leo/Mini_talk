/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:45 by lstorey           #+#    #+#             */
/*   Updated: 2024/04/12 16:50:12 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
			/*!SENDER!*/
void	text_sender(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i & 1) == 1)
			kill(pid, SIGUSR2);
		else if ((c >> i & 1) == 0)
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		message = argv[2];
		pid = ft_atoi(argv[1]);
		while (message[i] != '\0')
		{
			text_sender(pid, message[i]);
			i++;
		}
		text_sender(pid, '\0');
	}
	else
		ft_printf("error\n");
	return (0);
}
