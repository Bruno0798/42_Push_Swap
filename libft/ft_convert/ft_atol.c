/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:45:33 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 17:51:00 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	// Check for negative sign
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	// Iterate through each character of the string
	while (str[i] != '\0')
	{
		// Check if the character is a digit
		if (str[i] >= '0' && str[i] <= '9')
		{
			// Check if the result exceeds the maximum long number
			if (result > (LONG_MAX - (str[i] - '0')) / 10)
			{
				// Handle overflow
				return ((sign == 1) ? LONG_MAX : LONG_MIN);
			}
			// Update the result
			result = (result * 10) + (str[i] - '0');
		}
		else
		{
			// Invalid character, return 0
			return (0);
		}
		i++;
	}
	// Apply the sign
	return (result * sign);
}
