/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:56:50 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/17 15:18:52 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(void)
{
	/* 	t_stack *a;
		t_stack *b;
		int i;

		a = NULL;
		b = NULL;
		i = 2; */

	/* 	ft_check_args(argc, argv, a);
		create_stack(&a, ft_atoi(argv[1]));
		while (i < argc)
			ft_add_next(&a, ft_atoi(argv[i++])); */

	sort_five_asc_order_test();
	sort_five_min_at_top_test();
	sort_five_max_at_top_test();
	// sort(&a, &b);
	/* 	write(1, "\n", 1);
		print_stack(a); */
	// free_list(&a);
	// free_list(&b);

	return 0;
}