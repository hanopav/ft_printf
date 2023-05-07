/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:23:11 by phanosek          #+#    #+#             */
/*   Updated: 2023/05/06 18:11:04 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	num_length(int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len += 1;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*ret;
	unsigned int	nbr;

	len = num_length(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
	{
		ret[0] = '-';
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr == 0)
		ret[0] = '0';
	ret[len] = '\0';
	while (nbr != 0)
	{
		ret[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ret);
}

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
    int i;
    
    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_printstr(char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        ft_putstr("(NULL)");
        return (6);
    }
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(int a)
{
    int     len;
    char    *num;
    num = ft_itoa(a);
    len = ft_printstr(num);
    free(num);
    return(len);
}

int ft_percent(void)
{
    write(1, "%", 1);
    return (1);
}