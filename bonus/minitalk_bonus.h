/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:41:42 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/09 14:41:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

long	ft_atoi(const char *str);
void	ft_handler(int signum, siginfo_t *info, void *context);
int		ft_get_utf8_byte_count(unsigned char *c);

#endif
