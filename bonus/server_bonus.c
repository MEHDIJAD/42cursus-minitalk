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

#include "minitalk_bonus.h"

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
