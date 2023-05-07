/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:28:11 by phanosek          #+#    #+#             */
/*   Updated: 2023/05/06 18:10:53 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF
# define	FT_PRINTF

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int 	ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_putchar(char c);
int		ft_printstr(char *str);
int    	ft_putstr(char *str);
int		ft_putnbr(int n);
// void    ft_putptr();
int    	ft_percent(void);

#endif

