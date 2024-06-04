/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:00:16 by lstorey           #+#    #+#             */
/*   Updated: 2024/04/12 16:46:14 by lstorey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
			/*!RECIEVER!*/
char	*message_builder(char *message, char c)
{
	static char	temp[2];
	char		*temp_rtn;

	temp[0] = c;
	temp[1] = '\0';
	if (message == NULL)
	{
		message = ft_strdup(temp);
		return (message);
	}
	else
		 temp_rtn = ft_strjoin(message, temp);
	free(message);
	message = temp_rtn;
	return (message);
}

void	reciever(int bit)
{
	static int		i = 0;
	static char		c = 0;
	static char		*message;

	if (bit == SIGUSR2)
		c += 1 << i;
	else
		c += 0 << i;
	i++;
	if (i == 8)
	{
		message = message_builder(message, c);
		if (c == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	int		c;

	c = 1;
	printf("PID of the current process: %d\n", getpid());
	signal(SIGUSR2, reciever);
	signal(SIGUSR1, reciever);
	while (42)
	{
		pause();
	}
	return (0);
}
