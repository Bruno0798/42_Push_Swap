/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:56:50 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 14:38:42 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 2;
	ft_check_args(argc, argv, a);
	create_stack(&a, ft_atoi(argv[1]));
	while (i < argc)
		ft_add_next(&a, ft_atoi(argv[i++]));
	sort(&a, &b);
	print_stack(a);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
