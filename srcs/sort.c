/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:37:56 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/13 15:00:35 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_two(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_stack(a, 'a');
}

/**
 * Sorts a stack of three elements in ascending order.
 *
 * @param a - Pointer to the stack to be sorted
 */
void sort_three(t_stack **a)
{
	int min = get_min(*a);
	int max = get_max(*a);

	if (check_sort_list(*a))
	{
		// If the stack is already sorted, do nothing
		return;
	}

	if ((*a)->content != max && (*a)->next->content == min) // 2 1 3
	{
		// If the first element is the maximum and the second element is the minimum,
		// rotate the stack once to the left
		swap_stack(a, 'a');
	}
	else if ((*a)->content == max && (*a)->next->content != min) // 3 2 1
	{
		// If the first element is the maximum and the second element is not the minimum,
		// swap the first two elements and then reverse the stack
		swap_stack(a, 'a');
		reverse_stack(a, 'a');
	}
	else if ((*a)->content == max && (*a)->next->content == min) // 3 1 2
	{
		// If the first element is not the maximum and the second element is the minimum,
		// swap the first two elements
		rotate_stack(a, 'a');
	}
	else if ((*a)->content == min && (*a)->next->content == max) // 1 3 2
	{
		// If the first element is not the maximum and the second element is not the minimum,
		// reverse the stack
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else
	{
		// If none of the above conditions are met, reverse the stack
		reverse_stack(a, 'a');
	}
}

void sort_four(t_stack **a, t_stack **b)
{
	int min;

	min = get_min(*a);
	while ((*a)->content != min)
	{
		rotate_stack(a, 'a');
	}
	push_stack(a, b, 'b');
	sort_three(a);
	push_stack(b, a, 'a');
}

void sort_five(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = get_min(*a);
	max = get_max(*a);
	while ((*a)->content != min && (*a)->content != max)
		rotate_stack(a, 'a');
	if ((*a)->content == min)
		push_stack(a, b, 'b');
	sort_four(a, b);
	push_stack(b, a, 'a');
}

void sort(t_stack **a, t_stack **b)
{
	int len;

	len = stack_len(*a);
	if (len == 2)
		sort_two(a);
	else if (len == 3)
		sort_three(a);
	else if (len == 4)
		sort_four(a, b);
	else if (len == 5)
		sort_five(a, b);
	else
		sort_more(a, b);
}