/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:18:57 by mabaghda          #+#    #+#             */
/*   Updated: 2025/02/17 17:21:24 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	len_putchar(char c);
size_t	len_putstr(char *str);
size_t	len_putnbr(int nbr);
size_t	len_putunbr(unsigned int nbr);
size_t	len_puthex(unsigned long long n, int uppercase);
size_t	len_putptr(unsigned long long n);
int		ft_printf(const char *format, ...);

#endif
