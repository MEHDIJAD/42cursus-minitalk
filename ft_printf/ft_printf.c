/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:09:42 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 17:01:26 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	int		count;

	if (write(fd, 0, 0) == -1)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(fd, *(++format), ap);
		else
			count += write(fd, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
