/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:30:17 by phanosek          #+#    #+#             */
/*   Updated: 2023/02/09 16:44:25 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
