/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:09:34 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:37 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 0, power = 1, pid = 0;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0;
		bit = 0;
		power = 1;
	}
	if (signum == SIGUSR2)
		c += power;
	power *= 2;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
		power = 1;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	ft_printf(1, "server PID: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf(2, "sigaction failed\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf(2, "sigaction failed\n"), 1);
	while (1)
	{
		pause();
	}
	return (0);
}
