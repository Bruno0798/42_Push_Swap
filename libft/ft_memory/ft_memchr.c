/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:56:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/06/20 12:12:01 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	num;

	i = 0;
	d = (unsigned char *)s;
	num = (unsigned char)c;
	while (i < n)
	{
		if (d[i] == num)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
