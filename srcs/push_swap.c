/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:56:50 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/21 10:34:37 by bsousa-d         ###   ########.fr       */
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

	ft_check_args(argc, argv, a);			 // check if the args are valid
	create_stack(&a, ft_atoi(argv[1]));		 // create the stack a
	while (i < argc)						 // add the args to the stack a
		ft_add_next(&a, ft_atoi(argv[i++])); // add the args to the stack a

	sort(&a, &b); // sort the stack a

	ft_free_stack(&a); // free the stacks
	ft_free_stack(&b); // free the stacks

	return 0;
}

/* int main(void)
{
	// sort_three_numbers();
	//  sort_four_numbers();
	//  sort_five_numbers();
	//  sort_six_numbers();
	//  sort_seven_numbers();
	//sort_hundred_and_fifty();

	return 0;
} */