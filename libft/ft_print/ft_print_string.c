/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:40:32 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 11:07:14 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_string(char *s)
{
	size_t	i;

	i = -1;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[++i])
	{
		ft_putchar_fd(s[i], 1);
	}
	return (i);
}
