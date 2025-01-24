/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:59:57 by armarake          #+#    #+#             */
/*   Updated: 2025/01/24 21:48:01 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_parse_formatter(const char *str, va_list args)
{
	size_t	bytes;

	bytes = 0;
	if (*str == '%')
		bytes += f_putchar('%');
	if (*str == 'c')
		bytes += f_putchar(va_arg(args, int));
	if (*str == 's')
		bytes += f_putstr(va_arg(args, char *));
	if (*str == 'i' || *str == 'd')
		bytes += f_putnbr(va_arg(args, int));
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	size_t	bytes;
	va_list	args;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += ft_parse_formatter(str++, args);
		}
		else
		{
			bytes += f_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (bytes);
}

#include <stdio.h>
int main(void)
{
	printf("ft_printf bytes -> %d\n", ft_printf("Num 1: %d Num2: %d\n", 10, -10));
	printf("printf bytes -> %d\n", printf("Num 1: %d Num2: %d\n", 10, -10));
}
