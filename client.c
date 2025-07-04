/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:31:07 by cress             #+#    #+#             */
/*   Updated: 2025/06/28 23:29:52 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

static volatile int	g_signal_received = 0;

void	send_char_to_bin(int pid, char c)
{
	int			i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				write (1, "Error in Kill_SIGUSR1", 21);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				write (1, "Error in Kill_SIGUSR2", 21);
		}
		usleep(1000);
		while (g_signal_received == 0)
			pause();
		g_signal_received = 0;
		i++;
	}
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_signal_received = 1;
	}
	else if (sig == SIGUSR2)
	{
		write (1, "\nSent file\n", 11);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sig_client;

	if (argc == 3)
	{
		sig_client.sa_handler = signal_handler;
		sigemptyset(&sig_client.sa_mask);
		sig_client.sa_flags = 0;
		sigaction(SIGUSR1, &sig_client, NULL);
		sigaction(SIGUSR2, &sig_client, NULL);
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
			send_char_to_bin(pid, argv[2][i++]);
		send_char_to_bin(pid, '\0');
	}
	return (0);
}
