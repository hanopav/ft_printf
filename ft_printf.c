/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:49:54 by phanosek          #+#    #+#             */
/*   Updated: 2023/05/06 18:12:20 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int prlen;

	prlen = 0;
	if (format == 'c')
		prlen += ft_putchar(va_arg(args, int));
	else if (format == 's')
		prlen += ft_putstr(va_arg(args, char *));
	// else if (*str == 'p')
	// 	ft_putptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		prlen += ft_putnbr(va_arg(args, int));
	else if (format == '%')
		prlen += ft_percent();
	// else if (*str == 'u')
	// 	ft_uint(va_arg(args, int));
// 	else if (*str == 'x')
// 		ft_lowerhex(va_arg(args, ???));
// 	else if (*str == 'X')
// 		ft_upperhex(va_arg(args, int));
	return (prlen);
}

int ft_printf(const char *format, ...)
{
	int 	i;
	va_list	args;
	int		pr_len;

	i = 0;
	pr_len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			pr_len += ft_format(args, format[i + 1]);
			i++;
		}	
		else
			ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (pr_len);
}