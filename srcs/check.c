/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:08:06 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/10 22:23:25 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_isnum(char **num)
{
	int i;
	int j;

	j = 0;
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
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
			if (ft_strcmp(argv[i], argv[j++]) == 0)
				return (0);
		i++;
	}
	return (1);
}

void ft_check_args(char **argv, t_stack *stack)
{
	if (!ft_isnum(argv) || !ft_dup_check(argv))
	{
		ft_free_stack(stack);
		error();
	}
}