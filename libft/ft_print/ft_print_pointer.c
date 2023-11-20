/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:40:29 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 11:07:09 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_lenght(unsigned long c)
{
	int	len;

	len = 0;
	while (c)
	{
		len++;
		c /= 16;
	}
	return (len);
}

void	print_hexadecimal(unsigned long c)
{
	if (c >= 16)
	{
		print_hexadecimal(c / 16);
		print_hexadecimal(c % 16);
	}
	else
	{
		if (c <= 9)
			ft_print_char(c + '0');
		else
			ft_print_char(c - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long c)
{
	if (!c)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	print_hexadecimal(c);
	return (print_lenght(c) + 2);
}
