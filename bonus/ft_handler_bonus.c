/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:43:57 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/13 12:43:58 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_print(unsigned char *c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c[i], 1);
		i++;
	}
}

static void	ft_emptystock(unsigned char *c)
{
	int	i;

	i = 0;
	while (c[i])
		c[i++] = 0;
}

void	ft_excute(unsigned char *c, int *bytes, int *bit, int *power)
{
	*bit = 0;
	*power = 1;
	if (*bytes == ft_get_utf8_byte_count(c))
	{
		ft_print(c, *bytes);
		*bytes = 0;
		ft_emptystock(c);
	}
}

void	ft_message_received(siginfo_t *info)
{
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf(2, "kill failed\n");
		exit(1);
	}
}

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c[4];
	static int				bit;
	static int				power = 1;
	static int				pid;
	static int				bytes;

	(void)context;
	if (!pid || pid != info->si_pid)
	{
		pid = info->si_pid;
		bytes = 0;
		bit = 0;
		power = 1;
		ft_emptystock(c);
	}
	if (signum == SIGUSR2)
		c[bytes] += power;
	power *= 2;
	if (++bit == 8)
	{
		if (c[bytes] == '\0')
			ft_message_received(info);
		bytes++;
		ft_excute(c, &bytes, &bit, &power);
	}
}
