/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:08:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 22:10:32 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_isnum(char **num)
{
	int i;
	int j = 0;

	while (num[++j])
	{
		i = 0;
		if (num[j][0] == '-')
			i++;
		while (num[j][i])
			if (!ft_isdigit(num[j][i++]))
				return (0);
	}
	return (1);
}

static int ft_dup_check(char **argv)
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

void ft_check_args(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
		error();

	if (!ft_isnum(argv) || !ft_dup_check(argv)) // Check if the arguments are numbers and if there are duplicates
	{
		free_list(&stack);
		error();
	}
}