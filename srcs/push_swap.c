/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:56:50 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/10 22:43:57 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;

	if (argc < 2 || !check_args(argc, argv))
		return (0);

	a = create_stack(argc, argv);
	b = create_stack(0, NULL);

	sort(&a, &b);

	free_list(&a);
	free_list(&b);

	return 0;
}