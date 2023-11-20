/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:37:56 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/11/20 18:26:44 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void sort_two(t_stack **a) // Sort two numbers
{
	if ((*a)->content > (*a)->next->content) // If the first number is bigger than the second one, swap them
		swap_stack(a, 'a');
}

void sort_three(t_stack **a) // Sort three numbers
{
	int min = get_min(*a);
	int max = get_max(*a);

	if (check_sort_list(*a)) // If the list is already sorted,
		return;

	if ((*a)->content != max && (*a)->next->content == min) // 2 1 3
		swap_stack(a, 'a');

	else if ((*a)->content == max && (*a)->next->content != min) // 3 2 1
	{
		swap_stack(a, 'a');
		reverse_stack(a, 'a');
	}
	else if ((*a)->content == max && (*a)->next->content == min) // 3 1 2
		rotate_stack(a, 'a');

	else if ((*a)->content == min && (*a)->next->content == max) // 1 3 2
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else
		reverse_stack(a, 'a');
}

void sort_four(t_stack **a, t_stack **b) // Sort four numbers
{
	if (!(four_index(a, b, get_min_index(a)))) // If the index of the minimum number is 0, do nothing
		return;

	sort_three(a);
	push_stack(b, a, 'a');
}

void sort_five(t_stack **a, t_stack **b) // Sort five numbers
{

	if (!(five_index(a, b, get_min_index(a)))) // If the index of the minimum number is 0, do nothing
		return;

	push_stack(a, b, 'b');
	sort_four(a, b);
	push_stack(b, a, 'a');
}

void sort(t_stack **a, t_stack **b)
{
	int len = stack_len(*a);

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
