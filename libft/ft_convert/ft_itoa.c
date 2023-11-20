/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:55:43 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/12 16:15:17 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static long int count(long int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char *if_zero(char *str)
{
	str[0] = '0';
	return (str);
}

char *ft_itoa(int n)
{
	int num;
	char *c;
	long int nb;

	nb = n;
	num = count(nb);
	c = (char *)malloc(sizeof(char) * (num + 1));
	if (!c)
		return (NULL);
	c[num--] = '\0';
	if (nb == 0)
		return (if_zero(c));
	if (nb < 0)
	{
		c[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		c[num--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (c);
}
