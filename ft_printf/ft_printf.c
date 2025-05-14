/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaghda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:19:03 by mabaghda          #+#    #+#             */
/*   Updated: 2025/02/17 18:10:01 by mabaghda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

static size_t	check_format(char str, va_list args)
{
	size_t	len;

	len = 0;
	if (str == 'c')
		len += len_putchar(va_arg(args, int));
	else if (str == 's')
		len += len_putstr(va_arg(args, char *));
	else if (str == 'p')
		len += len_putptr(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		len += len_putnbr(va_arg(args, int));
	else if (str == 'u')
		len += len_putunbr(va_arg(args, unsigned int));
	else if (str == 'x')
		len += len_puthex(va_arg(args, unsigned int), 0);
	else if (str == 'X')
		len += len_puthex(va_arg(args, unsigned int), 1);
	else if (str == '%')
		len += len_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	size_t	len;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += check_format(format[i + 1], args);
			i++;
		}
		else
			len += len_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

//#include <stdio.h>
// int	main(void)
// {
// 	int	a;
// 	int	*m;
// 	int	count1;
// 	int	count2;

// 	a = 99824568;
// 	m = &a;
// 	count1 = 0;
// 	count2 = 0;
// 	count1 += ft_printf("The num is: %x\n", LONG_MAX);
// 	count2 += printf("The num is: %lx\n", LONG_MAX);
// 	printf("%d:", printf(" %lx ", LONG_MAX));
// 	printf("%d:", ft_printf(" %x ", LONG_MAX));
// 	ft_putnbr_fd(count1, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(count2, 1);
// 	write(1, "\n", 1);
// }
