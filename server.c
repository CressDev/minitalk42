/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cress <cress@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 19:31:17 by cress             #+#    #+#             */
/*   Updated: 2025/06/29 00:35:57 by cress            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static char	*g_new_str = NULL;

void	send_malloc(char c)
{
	char	*aux;
	char	str[2];
	char	*old_str;

	str[0] = c;
	str[1] = '\0';
	if (!g_new_str)
		g_new_str = ft_strdup("");
	if (!g_new_str)
	{
		write(1, "Error malloc inital\n", 20);
		exit(1);
	}
	old_str = g_new_str;
	aux = ft_strjoin(g_new_str, str);
	if (!aux)
	{
		write(1, "Error malloc aux\n", 17);
		exit(1);
	}
	g_new_str = aux;
	free(old_str);
}

void	wrt_str(__pid_t pid_client, char c)
{
	if (c == '\0')
	{
		if (g_new_str)
		{
			ft_printf("%s", g_new_str);
			write(1, "\n", 1);
			free(g_new_str);
			g_new_str = NULL;
		}
		if (kill(pid_client, SIGUSR2) == -1)
		{
			write (1, "Error in Kill_SIGUSR2", 21);
			exit(1);
		}
		return ;
	}
	send_malloc(c);
}

void	sig_to_char_handler(int sig, siginfo_t *info, void *context)
{
	static char			c;
	static int			i;
	static __pid_t		pid_client;

	(void)context;
	if (info->si_pid != 0)
		pid_client = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		wrt_str(pid_client, c);
		c = 0;
	}
	if (kill(pid_client, SIGUSR1) == -1)
	{
		write (1, "Error in Kill_SIGUSR1", 21);
		exit(1);
	}
}

int	main(void)
{
	__pid_t				pid;
	struct sigaction	sig_server;

	sig_server.sa_sigaction = sig_to_char_handler;
	sig_server.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_server.sa_mask);
	sigaddset(&sig_server.sa_mask, SIGUSR1);
	sigaddset(&sig_server.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig_server, NULL);
	sigaction(SIGUSR2, &sig_server, NULL);
	pid = getpid();
	ft_printf("__PID: %d\n", pid);
	sleep(1);
	while (1)
		pause();
	return (0);
}
