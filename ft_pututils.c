/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pututils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:46:30 by armarake          #+#    #+#             */
/*   Updated: 2025/01/24 21:49:28 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	f_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (sizeof(c));
}

size_t	f_putstr(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

size_t	f_putnbr(int n)
{
	size_t	len;

	ft_putnbr_fd(n, 1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
