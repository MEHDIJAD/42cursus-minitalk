/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_utf8_byte_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:57:08 by eel-garo          #+#    #+#             */
/*   Updated: 2025/03/13 14:57:10 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_get_utf8_byte_count(unsigned char *c)
{
	if (*c < 192)
		return (1);
	else if (*c < 224)
		return (2);
	else if (*c < 240)
		return (3);
	else
		return (4);
}
