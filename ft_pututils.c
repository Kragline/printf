/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:46:30 by armarake          #+#    #+#             */
/*   Updated: 2025/01/26 00:09:47 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	byte_putchar(char chr)
{
	ft_putchar_fd(chr, 1);
	return (sizeof(chr));
}

size_t	byte_putstr(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	byte_putnbr(int nbr)
{
	size_t	len;

	ft_putnbr_fd(nbr, 1);
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

size_t	byte_putunsigned(unsigned int nbr)
{
	size_t	bytes;

	bytes = 0;
	if (nbr > 9)
		bytes += byte_putunsigned(nbr / 10);
	bytes += byte_putchar(nbr % 10 + '0');
	return (bytes);
}
