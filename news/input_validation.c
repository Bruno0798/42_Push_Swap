/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:28:40 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/21 21:29:26 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_args(int argc, char **argv, t_stack *stack)
{
	if (argc < 2)
		exit(1);
	if (!ft_isnum(argv) || !ft_dup_check(argv))
	{
		ft_free_stack(&stack);
		error();
	}
}

int	ft_isnum(char **num)
{
	int	i;
	int	j;

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

int	ft_dup_check(char **argv)
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
