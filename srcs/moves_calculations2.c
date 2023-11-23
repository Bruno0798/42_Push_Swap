/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_calculations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:36:45 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/23 16:56:40 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_stack *stack, int target)
{
	int	index;

	index = 0;
	while (stack->content != target)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	out_min_max(t_stack *b, t_info info_a)
{
	t_info	info_b;
	int		target;

	target = get_max(b);
	info_b.size = stack_len(b);
	info_b.movements = get_index(b, target);
	return (mv_calcs(info_a, info_b));
}

int	in_min_max(t_stack *b, int data_a, t_info info_a)
{
	t_stack	*temp_b;
	t_info	info_b;
	int		target;

	temp_b = b;
	target = get_min(b);
	info_b.size = stack_len(b);
	while (temp_b != NULL)
	{
		if (data_a > temp_b->content)
		{
			if (target < temp_b->content)
				target = temp_b->content;
		}
		temp_b = temp_b->next;
	}
	info_b.movements = get_index(b, target);
	return (mv_calcs(info_a, info_b));
}

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
