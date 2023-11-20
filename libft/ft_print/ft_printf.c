/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:40:37 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 11:08:38 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(const char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long long)));
	else if (c == 'd')
		return (ft_print_decimal(va_arg(ap, int)));
	else if (c == 'i')
		return (ft_print_decimal(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_print_unsigned_decimal(va_arg(ap, int)));
	else if (c == 'x')
		return (ft_print_hexadecimal(va_arg(ap, int), 'a'));
	else if (c == 'X')
		return (ft_print_hexadecimal(va_arg(ap, unsigned int), 'A'));
	else if (c == '%')
		return (ft_print_percentage());
	else
		return (write(1, "0", 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	i = -1;
	len = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += ft_format(str[++i], ap);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
