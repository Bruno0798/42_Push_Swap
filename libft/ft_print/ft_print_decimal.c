/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:40:21 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/10/07 11:07:01 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_decimal(int c)
{
	char	*temp;
	size_t	size;

	if (!c)
		return (write(1, "0", 1));
	temp = ft_itoa(c);
	ft_putstr_fd(temp, 1);
	size = ft_strlen(temp);
	free(temp);
	return (size);
}
