/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armarake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:01:46 by armarake          #+#    #+#             */
/*   Updated: 2025/01/26 00:04:23 by armarake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	byte_putchar(char chr);
size_t	byte_putstr(char *str);
size_t	byte_putnbr(int nbr);
size_t	byte_puthex(unsigned long long nbr, int upper);
size_t	byte_putpointer(unsigned long long nbr);
size_t	byte_putunsigned(unsigned int nbr);

#endif