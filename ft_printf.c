/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:59:57 by armarake          #+#    #+#             */
/*   Updated: 2025/01/24 17:24:41 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_parse_formatter(const char *str, va_list args)
{
	size_t	bytes;
	(void) args;
	bytes = 0;
	if (*str == '%')
		bytes += f_putchar('%');
	if (*str == 'c')
		bytes += f_putchar(va_arg(args, int));
	if (*str == 's')
		bytes += f_putstr(va_arg(args, char *));
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	size_t	bytes;
	va_list args;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += ft_parse_formatter(str, args);
			str++;
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
	printf("ft_printf bytes -> %d\n", ft_printf("my man is 100%% goo%c %s\n", 'd', "guy"));
	printf("printf bytes -> %d\n", printf("my man is 100%% goo%c %s\n", 'd', "guy"));
}
