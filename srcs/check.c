/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:08:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/20 17:49:04 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_isnum(char **num) // Check if the arguments are numbers
{
	int i;
	int j = 0;

	while (num[++j]) // Loop through the arguments
	{
		i = 0;
		if (num[j][0] == '-') // If the number is negative, skip the first character
			i++;
		while (num[j][i])				  // Loop through the characters of the number
			if (!ft_isdigit(num[j][i++])) // Check if the character is a digit
				return (0);				  // If not, return 0
	}
	return (1); // If all the arguments are numbers, return 1
}

static int ft_dup_check(char **argv) // Check if there are duplicates
{
	int i = 1; // Start at 1 to skip the program name
	int j;

	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
			if (ft_strcmp(argv[i], argv[j++]) == 0) // Compare the current number with the next numbers
				return (0);
		i++;
	}
	return (1);
}

void ft_check_args(int argc, char **argv, t_stack *stack) // Check if the arguments are valid
{
	if (argc < 2) // If there are no arguments, exit
		error();

	if (!ft_isnum(argv) || !ft_dup_check(argv)) // Check if the arguments are numbers and if there are duplicates
	{
		ft_free_stack(&stack);
		error();
	}
}