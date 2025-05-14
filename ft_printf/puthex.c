/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:39:58 by mabaghda          #+#    #+#             */
/*   Updated: 2025/02/17 17:58:57 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_puthex(unsigned long long n, int uppercase)
{
	char	*base;
	size_t	len;

	len = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		len += len_puthex(n / 16, uppercase);
		len += len_puthex(n % 16, uppercase);
	}
	else
		len += len_putchar(base[n]);
	return (len);
}

size_t	len_putptr(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (!n)
	{
		len += len_putstr("0x0");
		return (len);
	}
	len += len_putstr("0x");
	len += len_puthex(n, 0);
	return (len);
}
