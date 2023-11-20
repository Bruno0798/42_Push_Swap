/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:22:49 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/06/20 14:23:28 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t			i;
	char			*arr;
	unsigned int	total;

	total = n * size;
	i = 0;
	arr = (char *)malloc(n * size);
	if (arr == NULL)
		return (NULL);
	while (total > 0)
	{
		arr[i] = 0;
		i++;
		total--;
	}
	return ((void *)arr);
}
