/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:09:29 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:31 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_pid;

void	ft_handelonechar(unsigned int c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_printf(2, "kill failed\n"), exit(1));
		}
		else if (c % 2 == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_printf(2, "kill failed\n"), exit(1));
		}
		usleep(200);
		usleep(200);
		c /= 2;
		i++;
	}
}

void	ft_sendmessage(char *argv, int pid)
{
	while (*argv)
	{
		ft_handelonechar(*argv, pid);
		argv++;
	}
	ft_handelonechar('\0', pid);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)signum;
	if (g_pid == info->si_pid)
		ft_printf(1, "message received\n");
}

int	check_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (ac == 3)
	{
		g_pid = ft_atoi(av[1]);
		if (g_pid <= 0 || !check_char(av[1]))
		{
			write(2, "Invalid PID\n", 12);
			exit(1);
		}
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			return (ft_printf(2, "sigaction failed\n"), 1);
		ft_sendmessage(av[2], g_pid);
	}
	else
	{
		write(2, "Usage: ./client <PID> <message>\n", 32);
		return (1);
	}
	return (0);
}
