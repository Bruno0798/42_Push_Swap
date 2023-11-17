/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:56:50 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 14:28:29 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int i;

	a = NULL;
	b = NULL;
	i = 2;

	ft_check_args(argc, argv, a);
	create_stack(&a, ft_atoi(argv[1]));
	while (i < argc)
		ft_add_next(&a, ft_atoi(argv[i++]));

	/* 	sort_four_asc_order_test();
		sort_four_min_at_top_test();
		sort_four_max_at_top_test();
	 */
	sort(&a, &b);
	/* 	write(1, "\n", 1);
		print_stack(a); */

	free_list(&a);
	free_list(&b);

	return 0;
}