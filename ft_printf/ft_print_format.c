/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:14:06 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/14 16:56:54 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(int fd, char format_specifier, va_list ap)
{
	int	count;

	count = 0;
	if (format_specifier == 'c')
		count += ft_printchar(fd, va_arg(ap, int));
	else if (format_specifier == 's')
		count += ft_printstr(fd, va_arg(ap, char *));
	else if (format_specifier == 'd' || format_specifier == 'i')
		count += ft_printdigit(fd, va_arg(ap, int), 10, "0123456789");
	return (count);
}
