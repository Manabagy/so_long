/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:19:01 by mabaghda          #+#    #+#             */
/*   Updated: 2025/02/17 15:35:29 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	len_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	len_putnbr(int nbr)
{
	size_t		len;
	char		*result;

	len = 0;
	result = ft_itoa(nbr);
	len = len_putstr(result);
	free(result);
	return (len);
}

size_t	len_putunbr(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr > 9)
	{
		len += len_putunbr(nbr / 10);
	}
	len += len_putchar(nbr % 10 + '0');
	return (len);
}
