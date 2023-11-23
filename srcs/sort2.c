/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:01:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/21 21:04:55 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	four_index(t_stack **a, t_stack **b, int index)
{
	if (index == 0)
		push_stack(a, b, 'b');
	if (index == 1)
	{
		rotate_stack(a, 'a');
		if (check_sort_list(*a))
			return (EXIT_SUCCESS);
		push_stack(a, b, 'b');
	}
	if (index == 2)
	{
		rotate_stack(a, 'a');
		rotate_stack(a, 'a');
		if (check_sort_list(*a))
			return (EXIT_SUCCESS);
		push_stack(a, b, 'b');
	}
	if (index == 3)
	{
		reverse_stack(a, 'a');
		if (check_sort_list(*a))
			return (EXIT_SUCCESS);
		push_stack(a, b, 'b');
	}
	return (EXIT_FAILURE);
}

bool	five_index(t_stack **a, t_stack **b, int index)
{
	if (index <= 2)
		four_index(a, b, index);
	if (index == 3)
	{
		reverse_stack(a, 'a');
		reverse_stack(a, 'a');
		if (check_sort_list(*a))
			return (EXIT_SUCCESS);
		push_stack(a, b, 'b');
	}
	if (index == 4)
	{
		reverse_stack(a, 'a');
		if (check_sort_list(*a))
			return (EXIT_SUCCESS);
		push_stack(a, b, 'b');
	}
	return (EXIT_FAILURE);
}

void	sort_more(t_stack **a, t_stack **b)
{
	t_info	info_a;
	t_info	nbr2sort;
	t_info	target;

	if (check_sort_list(*a))
		return ;
	push_stack(a, b, 'b');
	push_stack(a, b, 'b');
	info_a.size = stack_len(*a);
	while (info_a.size > 3)
	{
		nbr2sort = a_nbr2move(*a, *b, info_a);
		nbr2sort.size = stack_len(*a);
		target = b_target(*b, nbr2sort.data);
		target.size = stack_len(*b);
		sort_numbers(a, b, nbr2sort, target);
		info_a.size = stack_len(*a);
	}
	sort_three(a);
	put_all_a(a, b);
	rotating_a(a);
}
